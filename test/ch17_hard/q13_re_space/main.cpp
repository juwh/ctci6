#pragma region Interview Question
/*
17.13 Re-Space: Oh, no! You have accidentally removed all spaces, punctuation, and capitalization in a
lengthy document. A sentence like "I reset the computer. It still didn't boot!"
became "iresetthecomputeritstilldidntboot". You'll deal with the punctuation and capi-
talization later; right now you need to re-insert the spaces. Most of the words are in a dictionary but
a few are not. Given a dictionary (a list of strings) and the document (a string), design an algorithm
to unconcatenate the document in a way that minimizes the number of unrecognized characters.

EXAMPLE:
Input   jesslookedjustliketimherbrother
Output: jess looked just like tim her brother (7 unrecognized characters) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#496. Try a recursive approach.

#623. Can you just try all possibilities? What might that look like?

#656. You can think about the choices the recursive algorithm makes in one of two ways: (1)
At each character, should I put a space here? (2) Where should I put the next space? You
can solve both of these recursively.

#677. Will the recursive algorithm hit the same subproblems repeatedly? Can you optimize
with a hash table?

#739. In real life, we would know that some paths will not lead to a word. For example, there
are no words that start with hellothisism. Can we terminate early when going down
a path that we know won't work?

#749. For early termination, try a trie. 
*/
#pragma endregion