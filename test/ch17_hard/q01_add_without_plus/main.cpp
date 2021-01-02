#pragma region Interview Question
/*
17.1 Add Without Plus: Write a function that adds two numbers. You should not use + or any arithmetic
operators. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#467. Walk through binary addition by hand (slowly!) and try to really understand what is
happening.

#544. You can think about binary addition as iterating through the number, bit by bit, adding
two bits, and then carrying over the one if necessary. You could also think about it as
grouping the operations. What if you first added each of the bits (without carrying any
overflow)? After that, you can handle the overflow.

#601. Focus on just one of the steps above. If you "forgot" to carry the ones, what would the
add operation look like?

#628. The adding step alone would convert 1 + 1 -> 0, 1 + 0 -> 1, 0 + 1 -> 1, 0 + 0 -> 0. How do
you do this without the + sign?

#642. You can do the add step with an XOR.

#664. Now focus on the carrying. In what cases will values carry? How do you apply the carry
to the number?

#692. The carry will happen when you are doing 1 + 1. How do you apply the carry to the
number?

#712. You can use an AND operation to compute the carry. What do you do with it?

#724. You might need to do the add/carry operation more than once. Adding carry to sum
might cause new values to carry.





#469. 17.24 Start with a brute force solution.
#470. 17.14 There are actually several approaches. Brainstorm these. It's okay to start off with a naive
approach.
#475. 17.15 Try simplifying this problem: What if you just needed to know the longest word made
up of two other words in the list?
#477. 17.25 Start by grouping the dictionary by the word lengths, since you know each column has
to be the same length and each row has to be the same length.
#478. 17.7 Discuss the naive approach: merging names together when they are synonyms. How
would you identify transitive relationships? A == B, A == C, and C == D implies A
== D == B == C.
#480. 17.17 Start with a brute force solution. What is the runtime?
#484. 17.26 Solution 1: Start with just a simple algorithm comparing all documents to all other docu-
ments. How would you compute the similarity of two documents as fast as possible?
#485. 17.5 It doesn't really matter which letter or number it is. You can simplify this problem to just
having an array of As and Bs. You would then be looking for the longest subarray with
an equal number of As and Bs.
#486. 17.11 Consider first the algorithm for finding the closest distance if you will run the algorithm
only once. You should be able to do this in O(N) time, where N is the number of words
in the document.
#488. 17.9 Be clear about what this problem is asking for. It's asking for the kth smallest number in
the form 3^(a) * 5^(b) * 7^(c).
#492. 16.1 Try picturing the two numbers, a and b, on a number line.
#493. 17.7 The core part of the problem is to group names into the various spellings. From there,
figuring out the frequencies is relatively easy.
#495. 17.16 There are recursive and iterative solutions to this problem, but it's probably easier to
start with the recursive solution.
#496. 17.13 Try a recursive approach.
#498. 17.26 Solution 1: To compute the similarity of two documents, try reorganizing the data in
some way. Sorting? Using another data structure?
#499. 17.15 If we wanted to know just the longest word made up of other words in the list, then we
could iterate over all words, from longest to shortest, checking if each could be made up
of other words. To check this, we split the string in all possible locations.
#500. 17.25 Can you find a word rectangle of a specific length and width? What if you just tried all
options?
#501. 17.11 Adapt your algorithm for one execution of the algorithm for repeated executions. What
is the slow part? Can you optimize it?
#503. 17.19 Start with the first part: Finding the missing number if only one number is missing.
#504. 17.16 Recursive solution: You have two choices at each appointment (take the appointment
or reject the appointment). As a brute force approach, you can recurse through all possi-
bilities. Note, though, that if you take request i, your recursive algorithm should skip
request i + 1.
#506. 17.22 Start with a brute force, recursive solution. Just create all words that are one edit away,
check if they are in the dictionary, and then attempt that path.
#508. 17.9 What does a brute force solution to get the kth smallest value for 3^(a) * 5^(b) * 7^(c) look
like?
#509. 17.12 Try a recursive approach.
#510. 17.26 Solution 1: You should be able to get an O(A+B) algorithm to compute the similarity of
two documents.
#511. 17.24 The brute force solution requires us to continuously compute the sums of each matrix.
Can we optimize this?
#512. 17.7 One thing to try is maintaining a mapping of each name to its "true" spelling. You would
also need to map from a true spelling to all the synonyms. Sometimes, you might need
to merge two different groups of names. Play around with this algorithm to see if you
can get it to work. Then see if you can simplify/optimize it.
#515. 17.5 Start with a brute force solution.
#516. 17.16 Recursive solution: You can optimize this approach through memoization. What is the
runtime of this approach?
#518. 17.26 Solution 1: What is the relationship between the intersection and the union? Can you
compute one from the other?
#519. 17.20 Recall that the median means the number for which half the numbers are larger and half
the numbers are smaller.
#522. 17.10 Start with a brute force solution. Can you just check each value to see if it's the majority
element? 
#525. 17.24 Can you do any sort of precomputation to make computing the sum of a submatrix
O(1)?
#526. 17.16 Recursive solution: The runtime of your memoization approach should be O(N), with
O(N) space.
#530. 17.14 Consider thinking about reorganizing the data in some way or using additional data
structures.
#534. 17.26 Solution 1: To understand the relationship between the union and the intersection of
two sets, consider a Venn diagram (a diagram where one circle overlaps another circle).
#535. 17.22 Once you have a brute force solution, try to find a faster way of getting all valid words
that are one edit away. You don't want to create all strings that are one edit away when
the vast majority of them are not valid dictionary words.
#537. 17.7 An easier way of taking the above approach is to have each name map to a list of alter-
nate spellings. What should happen when a name in one group is set equal to a name in
another group?
#538. 17.11 You could build a lookup table that maps from a word to a list of the locations where
each word appears. How then could you find the closest two locations?
#539. 17.24 What if you precomputed the sum of the submatrix starting at the top left corner and
continuing to each cell? How long would it take you to compute this? If you did this,
could you then get the sum of an arbitrary sub matrix in O(1) time?
#542. 17.16 Iterative solution: Take the recursive solution and investigate it more. Can you imple-
ment a similar strategy iteratively?
#543. 17.15 Extend the earlier idea to multiple words. Can we just break each word up in all possible
ways?
#546. 17.20 Note that you have to store all the elements you've seen. Even the smallest of the
first 100 elements could become the median. You can't just toss very low or very high
elements.
#547. 17.26 Solution 2: It's tempting to try to think of minor optimizations-for example, keeping
track of the min and max elements in each array. You could then figure out quickly, in
specific cases, if two arrays don't overlap. The problem with that (and other optimiza-
tions along these lines) is that you still need to compare all documents to all other docu-
ments. It doesn't leverage the fact that the similarity is sparse. Given that we have a lot
of documents, we really need to not compare all documents to all other documents
(even if that comparison is very fast). All such solutions will be O(D^(2)), where D is the
number of documents. We shouldn't compare all documents to all other documents.
#550. 17.9 In looking for the kth smallest value of 3^(a) * 5^(b) * 7^(c), we know that a, b, and c will be
less than or equal to k. Can you generate all such numbers?
#552. 17.14 Can you sort the numbers?
#554. 17.16 Iterative solution: It's probably easiest to start with the end of the array and work back-
wards.
#555. 17.26 Solution 2: If we can't compare all documents to all other documents, then we need to
dive down and start looking at things at the element level. Consider a naive solution
and see if you can extend that to multiple documents.
#556. 17.22 To quickly get the valid words that are one edit away, try to group the words in the
dictionary in a useful way. Observe that all words in the form b_ll (such as bill, ball,
bell, and bull) will be one edit away. However, those aren't the only words that are
one edit away from bill.
#558. 17.11 If you had a list of the occurrences of each word, then you are really looking for a pair
of values within two arrays (one value for each array) with the smallest difference. This
could be a fairly similar algorithm to your initial algorithm.
#561. 17.26 Solution 2: One way to think about this is that we need to be able to very quickly pull
a list of all documents with some similarity to a specific document. (Again, we should
not do this by saying "look at all documents and quickly eliminate the dissimilar docu-
ments." That will be at least O(D^(2)).)
#562. 17.16 Iterative solution: Observe that you would never skip three appointments in a row. Why
would you? You would always be able to take the middle booking.
#565. 17.24 If you can precompute the sum from the top left corner to each cell, you can use this to
compute the sum of an arbitrary submatrix in O(1) time. Picture a particular submatrix.
The full, precomputed sum will include this submatrix, an array immediately above it
(C), and array to the left (B), and an area to the top and left (A). How can you compute
the sum of just D?
#566. 17.10 Consider the brute force solution. We pick an element and then validate if it's the
majority element by counting the number of matching and non-matching elements.
Suppose, for the first element, the first few checks reveal seven non-matching elements
and three matching elements. Is it necessary to keep checking this element?
#568. 17.16 Iterative solution: If you take appointment i, you will never take appointment i + 1,
but you will always take appointment i + 2 or i + 3.
#569. 17.26 Solution 2: Building off the earlier hint, we can ask what defines the list of documents
with some similarity to a document like {13, 16, 21, 3). What attributes does that list
have? How would we gather all documents like that?
#573. 17.6 Start with a brute force solution.
#575. 17.20 Another way to think about this is: Can you maintain the bottom half of elements and
the top half of elements?
#577. 17.26 Solution 2: The list of documents similar to {13, 16, 21, 3} includes all documents with a
13, 16, 21, and 3. How can we efficiently find this list? Remember that we'll be doing this
for many documents, so some precomputing can make sense.
#578. 17.16 Iterative solution: Use an example and work backwards. You can easily find the optimal
solution for the subarrays {r_(n)}, {r_(n-1), r_(n)}, {r_(n-2), ..., r_(n)}. How would you use
those to quickly find the optimal solution for {r_(n-3), ..., r_(n)}?
#580. 17.22 Create a mapping from a wildcard form (like b_ll) to all words in that form. Then, when
you want to find all words that are one edit away from bill, you can look up _ill,
b_ll, bi_l, and bil_ in the mapping.
#581. 17.24 The sum of just D will be sum(A&B&C&D) - sum(A&B) - sum(A&C) + sum(A).
#582. 17.17 Can you use a trie?
#584. 17.26 Solution 2: Try building a hash table from each word to the documents that contain this
word. This will allow us to easily find all documents with some similarity to {13, 16, 21, 3}.
#586. 17.7 If each name maps to a list of its alternate spellings, you might have to update a lot of
lists when you set X and Y as synonyms. If X is a synonym of {A, B, C}, and Y is a
synonym of {D, E, F} then you would need to add {Y, D, E, F} to A's synonym
list, B's synonym list, C's synonym list, and X's synonym list. Ditto for {Y, D, E, F}.
Can we make this faster?
#587. 17.16 Iterative solution: If you take an appointment, you can't take the next appointment, but
you can take anything after that. Therefore, optimal (r_(i), ..., r_(n)) = max(r_(i) +
optimal(r_(i+2), ..., r_(n)), optimal(r_(i+1), ..., r_(n))). You can solve this itera-
tively by working backwards.
#589. 17.15 When you get recursive algorithms that are very inefficient, try looking for repeated
subproblems.
#590. 17.19 Part 1: If you have to find the missing number in O(1) space and O(N) time, then you
can do a only constant number of passes through the array and can store only a few
variables.
#591. 17.9 Look at the list of all values for 3^(a) * 5^(b) * 7^(c). Observe that each value in the list will be
3*(some previous value), 5*(some previous value), or 7*(some previous value).
#593. 17.14 What about using a heap or tree of some sort?
#595. 17.24 With precomputation, you should be able to get a runtime of O(N^(4)). Can you make this
even faster?
#598 17.22 Your previous algorithm probably resembles a depth-first search. Can you make this
faster?
#603. 17.26 Solution 2: Once you have a way of easily finding the documents similar to a particular
document, you can go through and just compute the similarity to those documents
using a simple algorithm. Can you make this faster? Specifically, can you compute the
similarity directly from the hash table?
#604. 17.10 The majority element will not necessarily look like the majority element at first. It is
possible, for example, to have the majority element appear in the first element of the
array and then not appear again for the next eight elements. However, in those cases,
the majority element will appear later in the array (in fact, many times later on in the
array). It's not necessarily critical to continue checking a specific instance of an element
for majority status once it's already looking "unlikely."
#605. 17.7 Instead, X, A, B, and C should map to the same instance of the set {X, A, B, C}. Y, D,
E, and F should map to the same instance of {Y, D, E, F}. When we set X and Y as
synonyms, we can then just copy one of the sets into the other (e.g., add {Y, D, E,
F} to {X, A, B, C}). How else do we change the hash table?
#607. 17.16 Iterative solution: If you're careful about what data you really need, you should be able
to solve this in O(n) time and O(1) additional space.
#608. 17.12 Think about it this way: If you had methods called convertLeft and convertRight
(which would convert left and right subtrees to doubly linked lists), could you put those
together to convert the whole tree to a doubly linked list?
#609. 17.19 Part 1: What if you added up all the values in the array? Could you then figure out the
missing number?
#611. 17.26 Solution 2: Imagine you are looking up the documents similar to {1, 4, 6} by using a hash
table that maps from a word to documents. The same document ID appears multiple
times when doing this lookup. What does that indicate?
#612. 17.6 Rather than counting the number of twos in each number, think about digit by digit.
That is, count the number of twos in the first digit (for each number), then the number
of twos in the second digit (for each number), then the number of twos in the third digit
(for each number), and so on.
#615. 17.24 Suppose this was just a single array. How could we compute the subarray with the
largest sum? See 16.17 for a solution to this.
#617. 17.17 One solution is to insert every suffix of the larger string into the trie. For example, if the
word is dogs, the suffixes would be dogs, ogs, gs, and s. How would this help you
solve the problem? What is the runtime here?
#618. 17.22 A breadth-first search will often be faster than a depth-first search-not necessarily in
the worst case, but in many cases. Why? Can you do something even faster than this?
#619. 17.5 What if you just started from the beginning, counting the number of As and the number
of Bs you've seen so far? (Try making a table of the array and the number of As and Bs
thus far.)
#620. 17.10 Note also that the majority element must be the majority element for some subarray
and that no subarray can have multiple majority elements.
#621. 17.24 Suppose I just wanted you to find the maximum submatrix starting at row r1 and
ending at row r2, how could you most efficiently do this? (See the prior hint.) If I now
wanted you find the maximum subarray from r1 to (r2+2), could you do this effici-
ently?
#622. 17.9 Since each number is 3, 5, or 7 times a previous value in the list, we could just check all
possible values and pick the next one that hasn't been seen yet. This will result in a lot of
duplicated work. How can we avoid this?
#623. 17.13 Can you just try all possibilities? What might that look like?
#625. 17.14 If you picked an arbitrary element, how long would it take you to figure out the rank of
this element (the number of elements bigger or smaller than it)?
#626. 17.19 Part 2: We're now looking for two missing numbers, which we will call a and b. The
approach from part 1 will tell us the sum of a and b, but it won't actually tell us a and b.
What other calculations could we do?
#629. 17.21 What role does the tallest bar in the histogram play?
#633. 17.11 Can you just iterate through both arrays with two pointers? You should be able to do it
in O(A+B) time, where A and B are the sizes of the two arrays.
#636. 17.26 Solution 3: There's an alternative solution. Consider taking all of the words from all of the
documents, throwing them into one giant list, and sorting this list. Assume you could
still know which document each word came from. How could you track the similar pairs?
#638. 17.8 This problem asks us to find the longest sequence of pairs you can build such that both
sides of the pair are constantly increasing. What if you needed only one side of the pair
to increase?
#640. 17.21 Picture the tallest bar, and then the next tallest bar on the left and the next tallest bar on
the right. The water will fill the area between those. Can you calculate that area? What
do you do about the rest?
#641. 17.6 Is there a faster way of calculating how many twos are in a particular digit across a range
of numbers? Observe that roughly 1/10th of any digit should be a 2-but only roughly.
How do you make that more exact?
#645. 17.18 Start with a brute force solution.
#646. 17.12 Once you have a basic idea for a recursive algorithm, you might get stuck on this: some-
times your recursive algorithm needs to return the start of the linked list, and some-
times it needs to return the end. There are multiple ways of solving this issue. Brainstorm
some of them.
#647. 17.14 If you picked an arbitrary element, you would, on average, wind up with an element
around the 50th percentile mark (half the elements above it and half the elements
below). What if you did this repeatedly?
#649. 17.19 Part 2: There are a lot of different calculations we could try. For example, we could
multiply all the numbers, but that will only lead us to the product of a and b.
#650. 17.10 Try this: Given an element, start checking if this is the start of a subarray for which it's
the majority element. Once it's become "unlikely" (appears less than half the time), start
checking at the next element (the element after the subarray).
#651. 17.21 You can calculate the area between the tallest bar overall and the tallest bar on the left
by just iterating through the histogram and subtracting out any bars in between. You
can do the same thing with the right side. How do you handle the remainder of the
graph?
#652. 17.18 One brute force solution is to take each starting position and move forward until you've
found a subsequence which contains all the target characters.
#655. 17.7 An alternative approach is to think of this as a graph. How would this work?
#656. 17.13 You can think about the choices the recursive algorithm makes in one of two ways: (1)
At each character, should I put a space here? (2) Where should I put the next space? You
can solve both of these recursively.
#657. 17.8 If you needed only one side of the pair to increase, then you would just sort all the
values on that side. Your longest sequence would in fact be all of the pairs (other than
any duplicates, since the longest sequence needs to strictly increase). What does this tell
you about the original problem?
#658. 17.21 You can handle the remainder of the graph by just repeating this process: find the tallest
bar and the second tallest bar, and subtract out the bars in between.
#660. 17.9 Rather than checking all values in the list for the next value (by multiplying each by 3,
5, and 7), think about it this way: when you insert a value x into the list, you can "create"
the values 3x, 5x, and 7x to be used later.
#661. 17.14 Think about the previous hint some more, particularly in the context of quicksort.
#662. 17.21 How can you make the process of finding the next tallest bar on each side faster?
#666. 17.8 If you sort the values based on height, then this will tell you the ordering of the final pairs.
The longest sequence must be in this relative order (but not necessarily containing all
of the pairs). You now just need to find the longest increasing subsequence on weight
while keeping the items in the same relative order. This is essentially the same problem
as having an array of integers and trying to find the longest sequence you can build
(without reordering those items).
#669. 17.18 Another way of thinking about the brute force is that we take each starting index and
find the next instance of each element in the target string. The maximum of all these
next instances marks the end of a subsequence which contains all the target characters.
What is the runtime of this? How can we make it faster?
#671. 17.5 When the above tables have equal values for the number of As and Bs, the entire
subarray (starting from index 0) has an equal number of As and Bs. How could you use
this table to find qualifying subarrays that don't start at index 0?
#672. 17.19 Part 2: Adding the numbers together will tell us the result of a + b. Multiplying the
numbers together will tell us the result of a * b. How can we get the exact values for a
and b?
#675. 17.7 We can treat adding X, Y as synonyms as adding an edge between the X node and the Y
node. How then do we figure out the groups of synonyms?
#676. 17.21 Can you do precomputation to compute the next tallest bar on each side?
#677. 17.13 Will the recursive algorithm hit the same subproblems repeatedly? Can you optimize
with a hash table?
#678. 17.14 What if, when you picked an element, you swapped elements around (as you do in
quicksort) so that the elements below it would be located before the elements above
it? If you did this repeatedly, could you find the smallest one million numbers?
#680. 17.12 To handle whether your recursive algorithm should return the start or the end of the
linked list, you could try to pass a parameter down that acts as a flag. This won't work
very well, though. The problem is that when you call convert(current.left), you
want to get the end of left's linked list. This way you can join the end of the linked list
to current. But, if current is someone else's right subtree, convert(current)
needs to pass back the start of the linked list (which is actually the start of current.
left's linked list). Really, you need both the start and end of the linked list.
#681. 17.18 Consider the previously explained brute force solution. A bottleneck is repeatedly
asking for the next instance of a particular character. Is there a way you can optimize
this? You should be able to do this in O(1) time.
#682. 17.8 Try a recursive approach that just evaluates all possibilities.
#684. 17.23 Start with a brute force solution. Can you try the biggest possible square first?
#686. 17.9 When you add x to the list of the first k values, you can add 3x, 5x, and 7x to some new
list. How do you make this as optimal as possible? Would it make sense to keep multiple
queues of values? Do you always need to insert 3x, 5x, and 7x? Or, perhaps sometimes
you need to insert only 7x? You want to avoid seeing the same number twice.
#689. 17.19 Part 2: We could do both. If we know that a + b = 87 and a * b = 962, then we
can solve for a and b: a = 13 and b = 74. But this will also result in having to multiply
really large numbers. The product of all the numbers could be larger than 10^(157). Is there
a simpler calculation you can make?
#691. 17.18 Can you precompute the next instance of a particular character from each index? Try
using a multi-dimensional array.
#693. 17.21 As an alternative solution, think about it from the perspective of each bar. Each bar will
have water on top of it. How much water will be on top of each bar?
#695. 17.23 The biggest possible square is NxN. So if you try that square first and it works, then
you know that you've found the best square. Otherwise, you can try the next smallest
square.
#696. 17.19 Part 2: Almost any "equation" we can come up with will work here (as long as it's not
equivalent to a linear sum). It's just a matter of keeping this sum small.
#699. 17.8 Another way to think about the problem is this: if you had the longest sequence ending
at each element A[0] through A[n-1], could you use that to find the longest sequence
ending at element A[n-1]?
#701. 17.12 Many people get stuck at this point and aren't sure what to do. Sometimes they need
the start of the linked list, and sometimes they need the end. A given node doesn't
necessarily know what to return on its convert call. Sometimes the simple solution is
easiest: always return both. What are some ways you could do this?
#702. 17.19 Part 2: Try a sum of squares of the values.
#704. 17.7 Each connected subgraph represents a group of synonyms. To find each group, we can
do repeated breadth-first (or depth-first) searches.
#705. 17.23 Describe the runtime of the brute force solution.
#709. 17.20 What if you used a heap? Or two heaps?
#713. 17.5 Suppose, in this table, index i has count(A, 0->i) = 3 and count(B, 0->i) =
7. This means that there are four more Bs than As. If you find a later spot j with the same
difference (count(B, 0->j) - count(A, 0->j)), then this indicates a subarray
with an equal number of As and Bs.
#714. 17.23 Can you do preprocessing to optimize this solution?
#716. 16.1 Let diff be the difference between a and b. Can you use diff in some way? Then can
you get rid of this temporary variable?
#717. 17.19 Part 2: You might need the quadratic formula. It's not a big deal if you don't remember
it. Most people won't. Remember that there is such a thing as good enough.
#719. 17.12 You could return both the start and end of a linked list in multiple ways. You could
return a two-element array. You could define a new data structure to hold the start and
end. You could re-use the BiNode data structure. If you're working in a language that
supports this (like Python). you could just return multiple values. You could solve the
problem as a circular linked list, with the start's previous pointer pointing to the end
(and then break the circular list in a wrapper method). Explore these solutions. Which
one do you like most and why?
#721. 17.23 You should be able to do this in O(N^(3)) time, where N is the length of one dimension of
the square.
#725. 17.18 Once you have the precomputation solution figured out, think about how you can
reduce the space complexity. You should be able to get it down to O(SB) time and
O(B) space (where B is the size of the larger array and S is the size of the smaller array).
#731. 17.18 Another way to think about it is this: Imagine you had a list of the indices where each
item appeared. Could you find the first possible subsequence with all the elements?
Could you find the second?
#734. 17.21 Each bar will have water on top of it that matches the minimum of the tallest bar on the
left and the tallest bar on the right. That is, water_on_top[i] = min(tallest_
bar(0->i), tallest_bar(i, n)).
#736. 17.23 When you're checking to see if a particular square is valid (all black borders), you check
how many black pixels are above (or below) a coordinate and to the left (or right) of this
coordinate. Can you precompute the number of black pixels above and to the left of a
given cell?
#737. 16.1 You could also try using XOR.
#738. 17.22 What if you did a breadth-first search starting from both the source word and the desti-
nation word?
#739. 17.13 In real life, we would know that some paths will not lead to a word. For example, there
are no words that start with hellothisism. Can we terminate early when going down
a path that we know won't work?
#741. 17.18 Consider using a heap.
#742. 17.21 You should be able to solve this in O(N) time and O(N) space.
#743. 17.17 Alternatively, you could insert each of the smaller strings into the trie. How would this
help you solve the problem? What is the runtime?
#748. 17.25 Can you use a trie to terminate early when a rectangle looks invalid?
#749. 17.13 For early termination, try a trie. 
*/
#pragma endregion