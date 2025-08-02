#include "../hpp/App.hpp"

App ::App(char *files[])
{
    read_movies_file(files[2]);
    read_users_file(files[1]);

    auto movie_comparetor = [](const shared_ptr<Movie> &a, const shared_ptr<Movie> &b)
    {
        if (a->get_imdb() != b->get_imdb())
            return a->get_imdb() > b->get_imdb();
        return a->get_name() < b->get_name();
    };

    sort(movies.begin(), movies.end(), movie_comparetor);
    sort(sci_fi_movies.begin(), sci_fi_movies.end(), movie_comparetor);
    sort(action_movies.begin(), action_movies.end(), movie_comparetor);
    sort(comedy_movies.begin(), comedy_movies.end(), movie_comparetor);
    sort(drama_movies.begin(), drama_movies.end(), movie_comparetor);
    sort(horror_movies.begin(), horror_movies.end(), movie_comparetor);

    find_public_favorites();
}

shared_ptr<Movie> App::find_movie(string name)
{

    for (int i = 0; i < movies.size(); i++)
    {
        if (name == movies[i]->get_name())
        {
            return movies[i];
        }
    }

    return nullptr;
}

void App::read_users_file(char *file_address)
{
    fstream file(file_address);
    string temp_text;
    vector<string> tokens;
    int counter = 0;
    vector<string> temp_movies;
    vector<string> temp_rates;

    while (getline(file, temp_text))
    {
        if (counter != 0)
        {
            tokens = split_string(temp_text, COMMA);
            temp_movies = split_string(tokens[1], SEMICOLON);
            temp_rates = split_string(tokens[2], SEMICOLON);

            vector<pair<shared_ptr<Movie>, string>> movies_with_rates;

            for (int i = 0; i < temp_movies.size(); i++)
            {
                movies_with_rates.push_back(make_pair(find_movie(temp_movies[i]), temp_rates[i]));
            }

            auto temp_user = make_shared<User>(tokens[0], movies_with_rates);
            users.push_back(temp_user);
        }
        counter++;
    }
    file.close();
}

void App::read_movies_file(char *file_address)
{
    fstream file(file_address);
    string temp_text;
    vector<string> tokens;
    int counter = 0;

    while (getline(file, temp_text))
    {
        if (counter != 0)
        {
            tokens = split_string(temp_text, COMMA);
            auto temp_movie = make_shared<Movie>(tokens[0], tokens[1], tokens[2], tokens[3], stoi(tokens[4]));
            movies.push_back(temp_movie);

            int genre_num = genres[tokens[3]];
            switch (genre_num)
            {
            case 0:
                sci_fi_movies.push_back(temp_movie);
                break;
            case 1:
                action_movies.push_back(temp_movie);
                break;
            case 2:
                comedy_movies.push_back(temp_movie);
                break;
            case 3:
                drama_movies.push_back(temp_movie);
                break;
            case 4:
                horror_movies.push_back(temp_movie);
                break;
            }
        }
        counter++;
    }
    file.close();
}

void App::input_test()
{
    cout << "=== All Movies ===\n";
    for (const auto &m : movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Science Fiction ===\n";
    for (const auto &m : sci_fi_movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Action ===\n";
    for (const auto &m : action_movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Comedy ===\n";
    for (const auto &m : comedy_movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Drama ===\n";
    for (const auto &m : drama_movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Horror ===\n";
    for (const auto &m : horror_movies)
    {
        m->print_info();
        cout << "\n";
    }

    cout << "=== Users ===\n";
    for (const auto &u : users)
    {
        cout << "User: " << u->get_name() << "\n";
        for (const auto &p : u->get_movies())
        {
            cout << "Rated: " << p.second << "\n";
            p.first->print_info();
            cout << "\n";
        }
    }
}

void App::find_public_favorites()
{
    sci_fi_public_favorites = find_public_favorites_for_genre(sci_fi_movies);
    action_public_favorites = find_public_favorites_for_genre(action_movies);
    comedy_public_favorites = find_public_favorites_for_genre(comedy_movies);
    drama_public_favorites = find_public_favorites_for_genre(drama_movies);
    horror_public_favorites = find_public_favorites_for_genre(horror_movies);
}

vector<shared_ptr<Movie>> App::find_public_favorites_for_genre(vector<shared_ptr<Movie>> movies)
{
    vector<int> scores;
    int P;
    int A;
    int Z;
    int score;
    for (int i = 0; i < movies.size(); i++)
    {
        P = 0;
        A = 0;
        Z = 0;
        for (int j = 0; j < users.size(); j++)
        {
            auto user_movies = users[j]->get_movies();
            for (int k = 0; k < user_movies.size(); k++)
            {
                if (user_movies[k].first->get_name() == movies[i]->get_name())
                {
                    if (user_movies[k].second == PERFECT)
                    {
                        P++;
                    }
                    else if (user_movies[k].second == AVERAGE)
                    {
                        A++;
                    }
                    else if (user_movies[k].second == POOR)
                    {
                        Z++;
                    }
                }
            }
        }
        score = (7 * P) + (5 * A) + ((-2) * Z);
        movies[i]->set_public_score(score);
    }
    sort(movies.begin(), movies.end(),
         [](const shared_ptr<Movie> &a, const shared_ptr<Movie> &b)
         {
             return a->get_public_score() > b->get_public_score();
         });

    vector<shared_ptr<Movie>> output;
    output.push_back(movies[0]);
    output.push_back(movies[1]);
    output.push_back(movies[2]);

    return output;
}

vector<shared_ptr<Movie>> App::genre_rec_public(string genre)
{
    int genre_num = genres[genre];
    switch (genre_num)
    {
    case 0:
        return sci_fi_public_favorites;
        break;
    case 1:
        return action_public_favorites;
        break;
    case 2:
        return comedy_public_favorites;
        break;
    case 3:
        return drama_public_favorites;
        break;
    case 4:
        return horror_public_favorites;
        break;
    }
}

vector<shared_ptr<Movie>> App::find_private_favorites_for_genre(vector<shared_ptr<Movie>> movies, shared_ptr<User> user)
{
    vector<int> scores;
    int director_effect;
    int cast_effect;
    int score;
    for (int i = 0; i < movies.size(); i++)
    {
        }
    sort(movies.begin(), movies.end(),
         [](const shared_ptr<Movie> &a, const shared_ptr<Movie> &b)
         {
             return a->get_public_score() > b->get_public_score();
         });

    vector<shared_ptr<Movie>> output;
    output.push_back(movies[0]);
    output.push_back(movies[1]);
    output.push_back(movies[2]);

    return output;
}

vector<shared_ptr<Movie>> App::genre_rec_private(string genre)
{
    int genre_num = genres[genre];
    switch (genre_num)
    {
    case 0:
        return sci_fi_public_favorites;
        break;
    case 1:
        return action_public_favorites;
        break;
    case 2:
        return comedy_public_favorites;
        break;
    case 3:
        return drama_public_favorites;
        break;
    case 4:
        return horror_public_favorites;
        break;
    }
}