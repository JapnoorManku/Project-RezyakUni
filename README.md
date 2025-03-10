# CPSC2720 Two Week Project Rezyak
1. Team members : manj2720, moha2720, patx2720, zguo2720
2. Design: To manage our design phase we set up multiple group meetings where we went over our own designs and ultimately decided on 2. We also set up a group discord chat where we could ask questions and schedule additional meetings.

    How manj2720 contributed: Contributed to project designs, attended group meetings, created diagram to hand in.

    How moha2720 contributed: Contributed to project designs, attended group meetings.

    How patx2720 contributed: Contributed to project designs, attended group meetings, created diagram to hand in.

    How zguo2720 contributed: Contributed to project designs, attended group meetings.

3. The final design and implementation uses 
    Inheritance
    Polymorphism
    Program to the Interface not the implementation Principle
    Abstract what is common, Enacapsulate what varies Principle
    Single Responsibility Principle

4. The program is developed in C++ using Visual Studio Code.
5. The classes created are saved in files with names in PascalCase such as Game.hpp, Game.cpp, or GameTest.cpp, SpinnerTest.cpp, etc.
6. All class header files have .hpp extension and are saved in the include directory. Header files included are Bet.hpp, Game.hpp, Player.hpp, Spinner.hpp, Exceptions.hpp, MakeRandomInt.hpp
7. All class implementation files have .hpp extension and are saved in the src directory. Class implementation files included are Bet.cpp, Game.cpp, Player.cpp, Spinner.cpp, LowStakesSpinner.cpp, MediumStakesSpinner.cpp, HighStakesSpinner.cpp
8. The main function is saved in a file nmed main.cpp and is saved in the src/project directory.
9. The feature branch CPSC2720-Rayzak is created from latest main branch and merged into the main after committing and pushing from feature branch. While merging to the main branch, the feature branch is not deleted.
10. The Makefile provided is used for running continous integration.
11. The software program compiles on the department lab computers (make compile_project); passes style analysis (make style), passes static analysis (make static), pass memory leak checking (make memcheck)
12. The Coding advice is followed.
13. The URL of the GitLab repository is http://gitlab.cs.uleth.ca/small_projects_cpsc2720/group_14/two-week-project
14. The course instructor (@anvik), lab instructor (@wilsonn), amd marker (@mark27201) are invited to the repository as reporters.
15. How each team member contributed:

    manj2720: Contributed to development of Bet, Spinner, Player, Game and main header and implemetation files, test class files, comments, etc. Attended group meetings for coordination and collaboration in person and over online platform discord.

    patx2720: Contributed to development of Bet, Spinner, Player, Game and main header and implemetation files, test class files, comments, etc. Attended group meetings for coordination and collaboration in person and over online platform discord.

    zguo2720: Contributed to development of Bet, Spinner, Player, Game and main header and implemetation files, test class files, comments, etc. Attended group meetings for coordination and collaboration in person and over online platform discord.

    moha2720: Contributed to project designs, attended group meetings and doxyg comments.

16. The UML diagram of the final design of the project is availbale in design folder in docs. The diagram shows 
    The Class names
    Method names with their parameter types
    Variable names
    Relationships (inheritance, dependency, composition)
17. The required classes are implemented and used.
18. All stages of the pipeline pass.
        staticAnalysis (make static)
        styleCheck (make style)
        buildTest (make project)
19. At the command line the program runs without fault
        Program plays the game (./project)
        There are no memory leaks (make memcheck).
20. Evidence of using versioncontrol to manage group work
    http://gitlab.cs.uleth.ca/small_projects_cpsc2720/group_14/two-week-project/-/tree/CPSC2720-Rayzak?ref_type=heads

    The repository shows progress in completing the project over the duration of the project by having at least ten commits on at least six different dates.

    Stages of completion are documented by the use of meaningful commit messages.
21. No other files have been altered that shouldn't change.
    The only files you may alter or add include:
    (1) The header files in include.
    (2) The implementation files in src and src/project.
    (3) .gitignore
    (4) README.md
22. No unnecessary files have been committed to the repository. None of the material that can be generated such as the documentation, coverage report, or executables. None of the directories or files used by Visual Studio Code.
23. General Setup
    1. A player starts with 50 Zephy. (1 Zephy is equivalent to $6 from the Solarian country of Canada.)
    2. There are three types of spinners used, depending on what the player bets:
    a. Low Stakes: The spinner favours the player to get them to play more. This spinner produces more low numbers, which increases the
    likelihood of the player reaching the limit.
    b. Medium Stakes: The spinner is fair. All numbers are equally likely.
    c. High Stakes: The spinner cheats the player. This spinner produces more high numbers which increases the likelihood of the player going
    over the limit.
24. About the Game
    Rezyak is a casino game played in the Rigel-7 system.
    A. Components
    1. The game uses two spinners that each produce random numbers from different ranges of numbers.
    a. One spinner produces random numbers from the 2-5 range.
    b. One spinner produces random numbers from the 0-7 range.
    2. The currency used is the Rigel-7 Zephy1
    .
    B. Goal
    1. Get as close to the limit of 17 without going over.
    C. How to play
    1. Place a bet according to the stakes you want to play:
    a. Low Stakes: 5 Zephy.
    b. Normal Stakes: 25 Zephy.
    c. High Stakes: 50 Zephy.
    2. Choose a spinner.
    3. If the player chooses not to spin, the game pays out according to the following chart in requirements document.

    Enjoy!
