# OJ 
Record the answers I have done from the online judge platform .(e.g.[PTA](https://pintia.cn/),[LeetCode](https://leetcode.com/),[CodeWar](http://www.codewars.com)...)

**WARNING** 
- State: Still on :construction:, update daily as much as possible!
<!-- ## How to test snippets ?
- I recorded some useful algorithms in Tools/Snippets/, and also wrote some unit tests to illustrate the usage of these snippets
- Now, Only support test them manually... :cyclone:
- For example:
```bash
$ export CPLUS_INCLUDE_PATH=<PATH-TO>/OJ/Tools/third_party_libs/unit_test/ # G++
$ g++ test_<TEST_NAME> # Compile single test
$ ./a.out # Check Test Result
```
- Will change this way in the future, expecting! -->

# Project structure
```
 *THIS_REPO*
      │
      ├── Leetcode/             # [Leetcode](https://leetcode-cn.com/)
      ├── PTA/                  # [ZJU-PTA](https://pintia.cn/)
      │   ├── DS_2019_Spring/   # [ZJU-MOOC](https://www.icourse163.org/learn/ZJU-93001#/learn/announce)
      │   ├── PAT_A/            # [PAT_Advanced](https://pintia.cn/problem-sets/994805342720868352)
      │   │   ├── Cpp11/
      │   │   └── Python3/
      │   └── PAT_B/            # [PAT_Basic](https://pintia.cn/problem-sets/994805260223102976/problems/type/7)
      │       ├── Cpp11/
      │       └── Python3/
      ├── notes/                # My Notes extracted from these exams
      │   ├── ACM@
      │   └── snippets/
      │       ├── cpp/
      │       └── py/
      ├── tools/                # Helper Scripts for this project 
      │   ├── assistant/
      │   └── oj-snippets/
      ├── unstable/
      ├── LICENSE
      └── README
```

# Tools:
## OJ-snippets
- A vscode snippets extension for support the exams some common comments 
### Install 
- Copy this directory(`oj-snippets/`) to your vscode extensions folder and reload vscode, The location of extensions folder(Default):
  - Windows %USERPROFILE%\.vscode\extensions
  - macOS ~/.vscode/extensions
  - Linux ~/.vscode/extensions

- Now your can use some snippets to note some exams information:
  - [learn more](tools/oj-snippets/README.md)

### Uninstall
- Just delete this directory(`oj-snippets/`) in your vscode extensions folder and reload vscode.

## `assistant/` 
- Some internal scripts for enhance coding experience


# Notes:
- Retrieve the notes(git-submodule):
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


<!-- # 3rd-party:
:octocat:
- [Catch2](https://github.com/catchorg/Catch2) : A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD
 -->
