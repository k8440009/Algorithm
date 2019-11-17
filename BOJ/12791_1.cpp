// Starman
// https://www.acmicpc.net/problem/12791
#include <iostream>
#include <string>
using namespace std;
struct SONG
{
    int year;
    string name;
};
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SONG song[26] = {1967, "DavidBowie", 1969, "SpaceOddity", 1970, "TheManWhoSoldTheWorld", 1971, "HunkyDory",
                     1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", 1973, "AladdinSane",
                     1973, "PinUps", 1974, "DiamondDogs", 1975, "YoungAmericans", 1976, "StationToStation",
                     1977, "Low", 1977, "Heroes", 1979, "Lodger", 1980, "ScaryMonstersAndSuperCreeps",
                     1983, "LetsDance", 1984, "Tonight", 1987, "NeverLetMeDown", 1993, "BlackTieWhiteNoise",
                     1995, "1.Outside", 1997, "Earthling", 1999, "Hours", 2002, "Heathen", 2003, "Reality",
                     2013, "TheNextDay", 2016, "BlackStar"};

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e, cnt = 0;
        cin >> s >> e;
        for (int i = 0; i < 25; i++)
            if (song[i].year >= s && song[i].year <= e)
                cnt++;
        cout << cnt << '\n';
        for (int i = 0; i < 25; i++)
        {
            if (song[i].year >= s && song[i].year <= e)
                cout << song[i].year << ' ' << song[i].name << '\n';
        }
    }

    return 0;
}