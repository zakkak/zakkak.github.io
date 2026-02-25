---
title: Managed Runtime Systems
collection: courses
type: "Undergraduate course"
permalink: /teaching/managed-runtime-systems
venue: "University of Crete, Computer Science Department"
date: 2026-02-10
location: "Heraklion, Greece"
redirect_from:
  - /courses/managed-runtime-systems/
---

## Introduction

The aim of this course is to introduce students to the world of managed runtime systems.
Managed runtime systems are the ones responsible for executing managed programming languages, such as Python, Java, etc.
To improve performance such languages are usually compiled to some intermediate representation (e.g., bytecode) instead of native machine code; this intermediate representation is then parsed and executed by the corresponding managed runtime system.
In this course we study how managed programming languages are implemented in managed runtime systems.
The course is mainly focused on the Java programming language and the Java Virtual Machine (JVM).

## Syllabus

Lectures and tutorials will take place every **Tuesday**, **Thursday**, and **Friday** **09:00-11:00** at H.210 according to the schedule below.

Please note that the schedule is subject to change.

Looking at your markdown, the main issues are:

| Week       | #  | Tuesday                                            | Thursday                         | Friday                      |
|------------|----|----------------------------------------------------|----------------------------------|-----------------------------|
| 09/02/2026 | 1  | [Course Intro][]                                   | [VMs Intro][]                    | --                          |
| 16/02/2026 | 2  | [The JVM][]                                        | [GC Intro][]                     | [GC Intro][] Cont.          |
| 23/02/2026 | 3  | [JIT 1][]  [JIT 2][]                               | Paper 1: Interpreters            | --                          |
| 02/03/2026 | 4  | --                                                 | --                               | Paper 2: Call-site patching |
| 09/03/2026 | 5  | [Metacircularity and Native Compilation][metacirc] | Paper 3: GraalVM Native          | --                          |
| 16/03/2026 | 6  | [GC Intro 2][]                                     | Paper 4: Deconstructing G1       | TLABs and GC Tutorials      |
| 23/03/2026 | 7  | [Advanced GC][]                                    | Paper 5: GC Performance Impact   | --                          |
| 30/03/2026 | 8  | [Truffle][]                                        | Paper 6: One VM to Rule Them All | --                          |
| 06/04/2026 | -  | < Easter Break >                                   | < Easter Break >                 | < Easter Break >            |
| 13/04/2026 | -  | < Easter Break >                                   | < Easter Break >                 | < Easter Break >            |
| 20/04/2026 | 9  | [Java Concurrency & Concurrency][concurrency]      | Paper 7: Fray                    | JMH Tutorial                |
| 27/04/2026 | 10 | [Performance][]                                    | Paper 8: Performance             | < 1 May >                   |
| 04/05/2026 | 11 | Paper 9: TeraHeap                                  | Paper 10: Big Data GC            | --                          |
| 11/05/2026 | 12 | --                                                 | --                               | --                          |
| 18/05/2026 | 13 | Project Presentations                              | Project Presentations            | Project Presentations       |

[Course Intro]: /files/slides/00-selfintro.odp
[VMs Intro]: /files/slides/01-intro.odp
[The JVM]: /files/slides/02-jvms.odp
[GC Intro]: /files/slides/03-gc1.odp
[JIT 1]: https://speakerdeck.com/zakkak/managed-runtime-systems-lecture-05-just-in-time-compilation-part-1
[JIT 2]: https://www.dropbox.com/s/3uaajo2nc9g5qv4/11%20Dynamic%20optimization.pdf
[metacirc]: /files/slides/07-MetacirculatiryAndNative.odp
[GC Intro 2]: /files/slides/04-gc2.odp
[Advanced GC]: /files/slides/11-gc3.odp
[Truffle]: https://www.dropbox.com/s/l9rel49ux78ccav/15%20Truffle%20and%20Graal.pdf
[concurrency]: https://speakerdeck.com/zakkak/managed-runtime-systems-lecture-10-java-concurrency
[Performance]: https://speakerdeck.com/zakkak/the-art-of-java-performance-what-why-how

### Paper assignments

1. Interpreters: [Branch Prediction and the Performance of Interpreters - Don’t Trust Folklore](https://inria.hal.science/hal-01100647/document) -- csdp1491
2. Call-site patching: [Just-In-Time Compilation on ARM—A Closer Look at Call-Site Code Consistency](https://dl.acm.org/doi/full/10.1145/3546568) -- csd6079
3. GraalVM Native: [Initialize once, start fast: application initialization at build time](https://dl.acm.org/doi/abs/10.1145/3360610)
4. Deconstructing G1: [Deconstructing the Garbage-First garbage collector](https://users.cecs.anu.edu.au/~steveb/pubs/papers/g1-vee-2020.pdf) -- csd4203
5. GC Performance Impact: [Distilling the Real Cost of Production Garbage Collectors](https://www.steveblackburn.org/pubs/papers/lbo-ispass-2022.pdf) -- chemp1312
6. [One VM to rule them all](https://dl.acm.org/doi/pdf/10.1145/2509578.2509581) -- chem3749
7. [Fray: An Efficient General-Purpose Concurrency Testing Platform for the JVM](https://arxiv.org/pdf/2501.12618)
8. Performance: [Rethinking Java Performance Analysis](https://www.steveblackburn.org/pubs/papers/dacapo-asplos-2025-with-appendix.pdf)
9. [TeraHeap: Reducing Memory Pressure in Managed Big Data Frameworks](https://dl.acm.org/doi/pdf/10.1145/3582016.3582045) — Jack Kolokasis (tentative)
10. [Big Data GC: A Study on Garbage Collection Algorithms for Big Data Environments](https://www.researchgate.net/profile/Rodrigo-Bruno/publication/322371010_A_Study_on_Garbage_Collection_Algorithms_for_Big_Data_Environments/links/5afbff56aca272e7302ca76e/A-Study-on-Garbage-Collection-Algorithms-for-Big-Data-Environments.pdf)

#### Optional reading

10. Maxine: An approachable virtual machine for, and in, java
12. [Statistically Rigorous Java Performance Evaluation](https://dri.es/statistically-rigorous-java-performance-evaluation)
13. [The Truth, The Whole Truth, and Nothing But the Truth: A Pragmatic Guide to Assessing Empirical Evaluations](https://dl.acm.org/doi/pdf/10.1145/2983574)
14. [Producing wrong data without doing anything obviously wrong!](https://users.cs.northwestern.edu/~robby/courses/322-2013-spring/mytkowicz-wrong-data.pdf)
15. [Myths and Realities: The Performance Impact of Garbage Collection](https://www.cs.utexas.edu/~mckinley/papers/mmtk-sigmetrics-2004.pdf)

## Marking Scheme

| Component                   | Weight |
|-----------------------------|--------|
| Paper Presentation          | 15%    |
| Paper Abstracts & Discussion| 15%    |
| Class participation         | 20%    |
| Project                     | 50%    |
| Midterm                     | 0%     |
| Final exam                  | 0%     |

## Contact

You can contact me directly via e-mail `foivos+cs446 |at| zakkak |dot| net` or through the course's mailing list `2026 |at| mrs-course.groups.io`.

To subscribe send an email to: `2026+subscribe |at| mrs-course.groups.io` or visit [https://mrs-course.groups.io/g/2026](https://mrs-course.groups.io/g/2026).

## Material / Slides

The slides of the course are available as clickable links from the syllabus.

### Links

Below you can find a list of links pointing to material relevant to this course:

- [Repository with links to various resources avout the OpenJDK HotSpot JVM](https://github.com/perpap/OpenJDK-HotSpot-Deep-Dive)
- [Crafting Interpreters by Robert Nystrom](https://craftinginterpreters.com/contents.html)
- Tutorials about Building/Editing [OpenJDK](/tutorials/getting_started_with_openjdk_development/) and [GraalVM](/tutorials/getting_started_with_graalvm_development/)
- Tutorial on [configuring/using (G1)](http://www.oracle.com/technetwork/tutorials/tutorials-1876574.html)
- [Which Interpreters are Faster, AST or Bytecode?](https://stefan-marr.de/2023/10/ast-vs-bytecode-interpreters/) by [Stefan Marr](https://stefan-marr.de/)
- [Developers disassemble! Use Java and hsdis to see it all](https://blogs.oracle.com/javamagazine/post/java-hotspot-hsdis-disassembler) by [Chris Newland](https://mastodon.social/@chriswhocodes)
- [Dan Heidinga's Thoughts on Managed Runtimes](https://danheidinga.github.io/)
- [Aleksey Shipilëv's personal web site](https://shipilev.net/)
- [What lies beneath by Dmitry Vyazelenko and Maurice Naftalin (JPrime '19)](https://speakerdeck.com/mauricen/what-lies-beneath)
- [SO: How do I write a correct micro benchmark in java](https://stackoverflow.com/questions/504103/how-do-i-write-a-correct-micro-benchmark-in-java)

## Acknowledgments

### Guest lectures

- 2024 — I kindly thank Iakovos Kolokasis for presenting his work "TeraHeap: Reducing Memory Pressure in Managed Big Data Frameworks".
- 2019 — I kindly thank Dr. Heinz Kabutz for sharing his deep knowledge on Java threading and demoing how the JIT compiler can make Java programs behave in a "weird" way, while not breaking the Java Memory Model.
- 2018 — I kindly thank Dr. Christos Kotselidis for his insightful presentation regarding ["The Art of Java Performance"](https://speakerdeck.com/zakkak/the-art-of-java-performance-what-why-how) and the exciting live demo.

### Inspiration and Material

1. I would like to thank [Mario Wolczko](http://www.wolczko.com) for sharing his material and experiences from a similar course he taught at UC Berkeley. The original material of his course can be found [here](http://www.wolczko.com/CS294/index.html).
2. I would like to thank [Aleksey Shipilёv](https://shipilev.net/) for the creation of the ["JVM Anatomy Park"](https://shipilev.net/jvm-anatomy-park/) that provides a set of great examples and anecdotes to toy around in tutorials.

## Projects

You can either work alone or form a team of two. 
For your project you are encouraged to focus on JIT compilation or Garbage Collection, but you may also focus on something else as long as you can link it to the content of the course.

You shall choose and propose a project on your own. The project proposal should answer the following questions:

1. What do you find interesting in the project?
2. What do you expect to learn through this project implementation?
3. How are you going to demonstrate the success of your project?

You are strongly encouraged to work on OpenJDK or Graal VM for your project, but projects on other VMs (even non-Java VMs) will also be accepted.

Projects will be developed on github and will be based on the latest release of the corresponding VM you will choose to work on.

### Project Ideas / Past projects

- Object Hotness Tracking in G1GC for Tiered Heap Placement
- Write-Aware Object Migration Policy for Tiered Heap Systems
- See [MMTk's open student projects](https://github.com/mmtk/mmtk-core/issues?q=label%3AF-project) and [this tweet](https://twitter.com/stevemblackburn/status/1494240903888011269).
- Better Instruction Scheduling Heuristics for the JIT-centric Cranelift Compiler Backend.
- Project Proposal Generational Mark Sweep for MMTk.
- Comparative Performance Analysis of Language Implementations in GraalVM vs. Stock Runtime Environments.
- Extending Truffle's SimpleLanguage with Array types.
- Optimizations Performed by `javac`.
  - Identification of the optimizations performed by `javac` during compilation to bytecode. The team identified and located the `javac` source code responsible for the various optimizations performed by `javac` and provided source code examples for each optimization that `javac` optimized.
- Porting Maxine VM to Windows.
  - MaxineVM is not working on Windows. This project was about identifying what's needed to make MaxineVM work on Windows and implementing the missing parts. This project resulted in the following pull request on MaxineVM: https://github.com/beehive-lab/Maxine-VM/pull/21.
- MaxineVM: Support for Trampolines on RISC-V.
  - This project was about porting MaxineVM's implementation of trampolines for ARM processors to RISC-V. This project results in the following pull request on MaxineVM: https://github.com/beehive-lab/Maxine-VM/pull/19.
- Accelerating a Java FFT implementation on a GPU with TornadoVM.
  - The source codes of the two implementations are available at https://github.com/gkatev/TornadoFFT and https://gitlab.com/xvurakis/cs446.
- MaxineVM: Parallelization of the cross-ISA tests.
  - The source code of the implementation is available at https://github.com/Pyrromanis/maxine.
- Provide a Java API for an accelerated implementation of the Aho-Corasik algorithm.
  - The team provided the java API and evaluated against the standard pattern matching library provided by Java, and a Java implementation of Aho-Corasik.
- Add support for SGX-backed encryption in MaxineVM.
  - The team successfully substituted the corresponding OpenJDK methods to provide SGX-backed encryption transparently to the developer/application. They also evaluated their implementation against vanilla MaxineVM and OpenJDK HotSpot. The source code used to be available at https://github.com/dkarnikis/niqqer_vm/.
- Testing MaxineVM with AdoptOpenJDK's test scripts.
  - This project aimed to use AdoptOpenJDK's test scripts to test MaxineVM. The team studied the scripts and the tests providing a description for each of them. They also modified the scripts to make them work with MaxineVM and provided an evaluation of MaxineVM with pass/fail results and comments.
- A survey about Managed Runtime Systems in rust.
  - The team decided to enhance or try and implement (at least partially) a Javascript VM in rust. In their efforts they studied existing VMs and tried extending them.
- Hooking Maxine VM with External Disassembler.
  - MaxineVM comes with a built-in disassembler. This project aimed to hook MaxineVM with an external disassembler to make it easier to support more architectures without the need to extend the built-in disassembler.
- Evaluation of MaxineVM in comparison to HotSpot.
  - The team used the DaCapo benchmark suite to evaluate MaxineVM and compare its performance to HotSpot.
- Implementation of a Mark and Sweep Garbage Collector in a JS-like language.
- Extend Java concurrent lib with more concurrent data structures and evaluate them.
- Port MaxineVM to RISC-V.
  - The source code of the team's implementation is available at https://github.com/mvard/Maxine-VM.
- Identifying bottlenecks on MaxineVM.
- Evaluation of different Garbage Collectors.
- A memory manager implementation for C++ in C++.
- Evaluating the Performance of Interpreters Over Various Branch Predictors.
- Getting Familiar With Maxsim, A Simulation Platform For Managed Applications.
- Evaluation and comparison of Hotspot 1.7, Hotspot 1.8, MaxineVM, CACAO and JikesRVM.

### Project proposal deadline

Please submit your project proposals by **01/03/2026**!

The earlier you submit the more time we will have to discuss and fine tune your proposal.

## Reading Assignments

During this course you will be asked to read a number of scientific papers covering the topics at hand.
We will discuss each paper in the classroom to better understand them and answer any questions you might come up with.
Each of you will prepare and deliver a presentation for one of those papers, while the rest will be assigned to deliver a short summary for each of the papers they do not present.

### Summary format

Your summary should answer the following questions:

1. What is the key point of the paper? (If it is the survey, what are the key techniques it presents?)
2. What did you like the most in the paper?
3. What could be improved in the presentation/content of the paper?
4. Do you have any ideas on how to improve the presented idea/technique?
5. On a scale of 0-5, with 5 being the most positive, how would you rate the paper?

### Summary Submission

Please submit your summaries through email (in text or PDF format) by sending them to `foivos+cs446summary |at| zakkak |dot| net`.
The email subject should follow the pattern `[HY446] Summary: <Paper title>`, e.g. `[HY446] Summary: Garbage-First Garbage Collection`.
The summaries must be submitted before the beginning of the lecture where we will discuss the corresponding paper.

<!-- A Google form for each paper has been created, please fill it before the beginning of the lecture where we will discuss the corresponding paper. -->

<!--
* [The Structure and Performance of Efficient Interpreters (2003)](https://forms.gle/hwdnaEnX8oYjFNDZ8)
* [Garbage-First Garbage Collection (2004)](https://forms.gle/czMUTkHzdHEy3CDE9)
* [A Brief History of Just-In-Time (2003)](https://forms.gle/HmGj8Fbe6ezeZ4oPA)
* [Maxine: An approachable virtual machine for, and in, java (2013)](https://forms.gle/JMYZPBVfxpg1KMp59)
* [The Java Memory Model (2005)](https://forms.gle/jSPb5Vv1Sg6nJAPT9)
* [JDMM: A Java Memory Model for Non-Cache-Coherent Memory Architectures (2014)](https://forms.gle/11uxytqZwPCi3fqt8)
* [Statistically Rigorous Java Performance Evaluation (2007)](https://forms.gle/eQNLvftn1ga96FnG9)
-->
