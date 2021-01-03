#pragma region Interview Question
/*
17.26 Sparse Similarity: The similarity of two documents (each with distinct words) is defined to be the
size of the intersection divided by the size of the union. For example, if the documents consist of
integers, the similarity of {1, 5, 3} and {1, 7, 2, 3} is 0.4, because the intersection has size
2 and the union has size 5.
We have a long list of documents (with distinct values and each with an associated ID) where the
similarity is believed to be "sparse." That is, any two arbitrarily selected documents are very likely to
have similarity 0. Design an algorithm that returns a list of pairs of document IDs and the associated
similarity.
Print only the pairs with similarity greater than 0. Empty documents should not be printed at all. For
simplicity, you may assume each document is represented as an array of distinct integers.

EXAMPLE
Input:
    13: {14, 15, 100, 9, 3}
    16: {32, 1, 9, 3, 5}
    19: {15, 29, 2, 6, 8, 7}
    24: {7, 10}
Output:
    ID1, ID2 SIMILARITY
    13, 19  : 0.1
    13, 16  : 0.25
    19, 24  : 0.14285714285714285 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#484. Solution 1: Start with just a simple algorithm comparing all documents to all other docu-
ments. How would you compute the similarity of two documents as fast as possible?

#498. Solution 1: To compute the similarity of two documents, try reorganizing the data in
some way. Sorting? Using another data structure?

#510. Solution 1: You should be able to get an O(A+B) algorithm to compute the similarity of
two documents.

#518. Solution 1: What is the relationship between the intersection and the union? Can you
compute one from the other?

#534. Solution 1: To understand the relationship between the union and the intersection of
two sets, consider a Venn diagram (a diagram where one circle overlaps another circle).

#547. Solution 2: It's tempting to try to think of minor optimizations-for example, keeping
track of the min and max elements in each array. You could then figure out quickly, in
specific cases, if two arrays don't overlap. The problem with that (and other optimiza-
tions along these lines) is that you still need to compare all documents to all other docu-
ments. It doesn't leverage the fact that the similarity is sparse. Given that we have a lot
of documents, we really need to not compare all documents to all other documents
(even if that comparison is very fast). All such solutions will be O(D^(2)), where D is the
number of documents. We shouldn't compare all documents to all other documents.

#555. Solution 2: If we can't compare all documents to all other documents, then we need to
dive down and start looking at things at the element level. Consider a naive solution
and see if you can extend that to multiple documents.

#561. Solution 2: One way to think about this is that we need to be able to very quickly pull
a list of all documents with some similarity to a specific document. (Again, we should
not do this by saying "look at all documents and quickly eliminate the dissimilar docu-
ments." That will be at least O(D^(2)).)

#569. Solution 2: Building off the earlier hint, we can ask what defines the list of documents
with some similarity to a document like {13, 16, 21, 3). What attributes does that list
have? How would we gather all documents like that?

#577. Solution 2: The list of documents similar to {13, 16, 21, 3} includes all documents with a
13, 16, 21, and 3. How can we efficiently find this list? Remember that we'll be doing this
for many documents, so some precomputing can make sense.

#584. Solution 2: Try building a hash table from each word to the documents that contain this
word. This will allow us to easily find all documents with some similarity to {13, 16, 21, 3}.

#603. Solution 2: Once you have a way of easily finding the documents similar to a particular
document, you can go through and just compute the similarity to those documents
using a simple algorithm. Can you make this faster? Specifically, can you compute the
similarity directly from the hash table?

#611. Solution 2: Imagine you are looking up the documents similar to {1, 4, 6} by using a hash
table that maps from a word to documents. The same document ID appears multiple
times when doing this lookup. What does that indicate?

#636. Solution 3: There's an alternative solution. Consider taking all of the words from all of the
documents, throwing them into one giant list, and sorting this list. Assume you could
still know which document each word came from. How could you track the similar pairs?
*/
#pragma endregion