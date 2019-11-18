'''
    Starman
    https://www.acmicpc.net/problem/12791
'''

db = {
    1967: ["DavidBowie"],
    1969: ["SpaceOddity"],
    1970: ["TheManWhoSoldTheWorld"],
    1971: ["HunkyDory"],
    1972: ["TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"],
    1973: ["AladdinSane", "PinUps"],
    1974: ["DiamondDogs"],
    1975: ["YoungAmericans"],
    1976: ["StationToStation"],
    1977: ["Low", "Heroes"],
    1979: ["Lodger"],
    1980: ["ScaryMonstersAndSuperCreeps"],
    1983: ["LetsDance"],
    1984: ["Tonight"],
    1987: ["NeverLetMeDown"],
    1993: ["BlackTieWhiteNoise"],
    1995: ["1.Outside"],
    1997: ["Earthling"],
    1999: ["Hours"],
    2002: ["Heathen"],
    2003: ["Reality"],
    2013: ["TheNextDay"],
    2016: ["BlackStar"]
}

for _ in range(int(input())):
    s, e = map(int, input().split())

    cnt = 0
    strbuild = []

    for year in range(s, e + 1):
        if year not in db:
            continue
        for name in db[year]:
            strbuild.append(str(year))
            strbuild.append(' ')
            strbuild.append(name)
            strbuild.append('\n')
            cnt += 1

    print(cnt)
    print("".join(strbuild), end='')

'''
    참고
    https://wayhome25.github.io/python/2017/02/26/py-14-list/
'''
