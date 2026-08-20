# Competitive Programming

A personal archive of competitive programming work — contest solutions, practice problems, training notes, and a reusable C++ template library. Roughly 850 C++ solutions spanning Codeforces rounds, ICPC regionals and finals, CSES, USACO, IOI, and Meta Hacker Cup.

## Layout

| Path | What's inside |
| --- | --- |
| `codeforces/` | Round-by-round contest solutions (`contest/<id>/`) plus standalone practice problems |
| `cses/` | CSES Problem Set solutions |
| `ICPC/` | NAQ / NAC / PacNW regionals and finals by year, team training sets, and the team reference document |
| `ICPC/TRD template/` | Reusable algorithm implementations: DSU, Dijkstra, Floyd–Warshall, KMP, rolling hash, suffix array, centroid decomposition, convex hull + CHT, matrix exponentiation, sqrt decomposition, sweep line, LIS |
| `usaco guide/` | USACO division work and topic notes (e.g. Aliens trick) |
| `IOI/`, `Hacker Cup/`, `MIT tournament/`, `ACPC 2026/` | Solutions from other contests |
| `club/` | Weekly programming club sessions, organized by year and meeting date |

## Workflow

`template.cpp` is the starting point for every problem: `bits/stdc++.h`, common typedefs and macros, fast I/O, a seeded `mt19937_64`, and a `debug(...)` macro that is compiled out unless `AKIKO_DEBUG` is defined.

Spin up a new contest directory pre-filled with A–E stubs and a scratch input file:

```bash
./start.sh <contest-name>
```

Compile a solution with debug output enabled:

```bash
g++ -std=c++17 -O2 -DAKIKO_DEBUG A.cpp -o a.out && ./a.out < test
```
