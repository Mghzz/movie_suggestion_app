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
}

vector<string> split_string(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream sstr(str);
    while (getline(sstr, token, delimiter))
    {
        tokens.push_back(move(token));
    }
    return tokens;
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

    unordered_map<string, int> genres = {
        {SCIENCE_FICTION, 0},
        {ACTION, 1},
        {COMEDY, 2},
        {DRAMA, 3},
        {HORROR, 4}};

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
