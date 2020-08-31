# ACM-ICPC 2017 Jakarta Regional Repository

## Repository Structure

Each problem (from A to L) has their own folder. The folder name is the `slug` of the problem, which is the codename we used when we internally prepare the problems. The following table describes the slug for each problem

| Problem Code | Problem Slug | Problem Title               |
| ------------ | ------------ | --------------------------- |
| A            | matrix       | Simple Operations in Matrix |
| B            | market       | Mini Market                 |
| C            | polygonal    | Polygonal Query             |
| D            | diet         | Galatea's Diet              |
| E            | comboflip    | Flip and Combos             |
| F            | subset       | Maximum Subset              |
| G            | pair         | Largest Exotic Number       |
| H            | triangle     | Triangle of Safety          |
| I            | line         | Domino Line                 |
| J            | nosubs       | Inverse Common Superstring  |
| K            | adding       | Adding Numbers              |
| L            | table        | Pretty Table                |

In the problem folder, there should be at least the following file/folder:

- `solution.cpp`. The official solution used to generate the outputs of the testcases
- `tc/`. A folder consisting of all testcases. The sample inputs given in the problem statement will be in the form of `<slug>_sample_<testcase number>.in/out`, while the hidden testcases will be in the form of `<slug>_<testcase number>.in/out`.
- `icpc17-<problem code in lowercase>.pdf`. The problem statement distributed to the contestants during the contest.

For the problem with multiple correct outputs for each input, there should be one more file in the problem folder:

- `scorer.cpp`. The code accepts three arguments.
  - The first parameter will be used as the filename of the input file
  - The second parameter will not be used
  - The third parameter will be used as the filename of the judge's output file
  - The contestant's output will be read from standard input
  - This code will print `WA` if the contestant's output is intended to be judged `WRONG ANSWER`, while it will not output anything if the contestants's output is intended to be judged `CORRECT`.

## Limitations

The following table describes the time limit for each problem, as broadcasted to all teams at the beginning of the contest:

| Problem Code | Problem Slug | Time Limit |
| ------------ | ------------ | ---------- |
| A            | matrix       | 1 sec      |
| B            | market       | 1 sec      |
| C            | polygonal    | 1 sec      |
| D            | diet         | 1 sec      |
| E            | comboflip    | 2 sec      |
| F            | subset       | 1 sec      |
| G            | pair         | 1 sec      |
| H            | triangle     | 1 sec      |
| I            | line         | 1 sec      |
| J            | nosubs       | 1 sec      |
| K            | adding       | 0.5 sec    |
| L            | table        | 1 sec      |

The memory limit for all problems is 256MB, as announced in the technical briefing of the contest.

## Solutions

Note that while there are only two official published solutions, we have a lot of other solutions prepared for our internal testing. These other solutions include, but not limited to:

- Solutions in several other languages
- Solutions that is intended to be incorrect (e.g. WA, TLE, etc.)
- Other correct solutions (especially on problems with more than one correct outputs for each input)
