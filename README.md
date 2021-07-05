# A C(++) University Assignment

A C++ university assignment, paraphrased by The Cherno in the video [*I did a C++ University Assignment*](https://www.youtube.com/watch?v=kQsHF7C-FUY&ab_channel=TheCherno), and (hopefully) solved by me in C.

## The assignment

- Marked automatically
- "Failure to follow this guideline will result in 0."
- Exactly one file: main.cpp [or in my case, main.c]
- No design
- Implement a **very specific hash table**
- Keys are lower-case English words (eg. apple)
- Length of a key is at most 10
- Hash function = "simply using the last character" (eg. hash of apple is 'e')
- Hash table contains exactly 26 slots (a-z), you won't need more
- Table slots have three different statuses: "never used", "tombstone", "occupied"
- Table starts with never used
- Searching works as follows:
  - Given a key, take its last character as the hash value
  - First try the corresponding table slot
  - If the key is there, you've found it, if it's "never used", it doesn't exist
  - If the key is "occupied" or "tombstone", then move to next slot (may need to wrap the table)
  - Keep trying until key is found, or we're certain it doesn't exist
- Insertion works as follows:
  - First perform search to see if key exists - if it does, do nothing
  - Take the last character of key as hash value
  - If that slot is not cooupied ("never used" or "tombstone"), put the key there and
      occupy the slot
  - If it's occupied, try the next slot until you find a free slot
- Deletion works as follows:
  - Given a key, search for it to locate its slot (if it doesn't exist do nothing)
  - If found, change to "tombstone"
- When program starts init empty hash table (26 "never used" slots)
- Command line input is 1-26 "modification moves" separated by spaces, moves are:
  - **AWord** - (character **A** followed by a lower-case English word of up to 10
      characters)
    - eg. `Aapple` means insert key "apple" into hash table
  - **DWord** - (character **D** followed by word as above)
    - eg. `Dapple` means delete key "apple" from hash table
- Once input is processed, output is all the slots in the hash table that have
    "occupied" values, separated by spaces
- Ignore invalid inputs
  Sample input: Aapple Aorange Dapple Astrawberry
  Sample output: orange strawberry

- Submit via SVN
- Marking done automatically - total mark is 10
  - 1 mark for compiling
  - 9 marks for 9 test cases (1 per successful test case)
- Code compiled using `g++ -o main.out -std=c++11 -O2 -Wall main.cpp`

