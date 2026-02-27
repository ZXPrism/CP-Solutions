# CP-Solutions
This repository holds all my CP (Competitive Programming) solutions since `2025.01.26`.

## Summary of Key Ideas
- How to solve problems
  - think rigorously, never make uncertain assumption and believe your own intuition
  - plus some love
  - two main approaches to find clues (take CF1921F as an example)
    - playing with the example then generalize
    - write the exact formula and transform it (prefer a compact form since multple terms clutter your thinking)
  - even if you have the right idea, you may implement it in the wrong way, like
    - treating stepped indices as global indices --> should divide by step
    - ...
  - sometimes the answer is quite limited that you can even enumerate them!
- Binary Search
  - just an optimization tool, think about linear version first
  - on indexes -> explicit
  - on answers / values -> implicit
  - essentially find a boundary where the predicate fails / monotonicity flips
    - so don't be afraid when the candidate is invalid, as the algorithm will "auto" snaps the candidate to a valid one
- Sqrt Decomposition
  - find an equilibrium between multiple stretegies
- Find maximum/minimum etc.
  - if you can not directly (or hard to) tell which one is the maximum, can you enumerate all possible candidates and manually compute the maximum?
- Problems about bits / lexicographics
  - One digit in higher position outweighs any digit combination in lower position ---> leads to some greedy construction methods
