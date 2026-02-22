How to random shuffle a vector in cpp?

Idea 1:
Generate a vector of the same length as the input vector and fill it with 
random numbers without replacement in 0, len(vector)-1

Shuffle the actual vector by switching like this: vector[i] = vector[random_vector[i]]

example: 
vector = [aaron, durian, andrej, charlie]
random_vector = [2,3,1,0]

new_vector = [andrej, charlie, durian, aaron]
---
But how to get a vector with random numbers in [0, len(vec)) with no replacement?
Turns out this is not that easy.
But cpp has a random shuffle function!!!

But what how does random shuffle work internally?
I found that there is an algo named Fisher-Yates shuffle algo, that iterates through a list and swaps each element with a random index. Seems easy & fun! I'll implement it.

Idea 2
Fisher-Yates shuffle algo
Whar should be the correct input & output for such an algo? For me vector<string> -> shuffled vector<string> works
