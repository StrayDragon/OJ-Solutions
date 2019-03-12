# OJ
Record the answers I have done from the online judge platform .(e.g.[PTA](https://pintia.cn/),[LeetCode](https://leetcode.com/),[CodeWar](http://www.codewars.com)...)

## How to test snippets ?
- I recorded some useful algorithms in Tools/Snippets/, and also wrote some unit tests to illustrate the usage of these snippets
- Now, Only support test them manually... :cyclone:
- For example:
```bash
$ export CPLUS_INCLUDE_PATH=<PATH-TO>/OJ/Tools/third_party_libs/unit_test/ # G++
$ g++ test_<TEST_NAME> # Compile single test
$ ./a.out # Check Test Result
```
- Will change this way in the future, expecting!

# Notes:
- Retrive the notes(git-submodule):
- If you haven't already pulled my repo(OJ), just use this command:
```bash
$ git clone https://github.com/StrayDragon/OJ.git --recursive
```
- Otherwise
```bash
git clone https://github.com/StrayDragon/OJ.git
cd Oj
git submodule init
git submodule update
```
## Notes(submodule) list:
- notes/ACM/ https://github.com/LittileNiQ/ACM.git

# 3rd-party:
:octocat:
- [Catch2](https://github.com/catchorg/Catch2) : A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD