# Markov-Text-Generator

Takes a .txt file as an input and uses it to create a Markov chain in which each word from the text is treated as a state.
The transition probabilities of the chain are then used to generate text.

### Example 1
In this example, I use Harry Potter and the Sorcerer's Stone as an input file. Here are some examples of the generated text:
-  madam hooch was singing along it only a steep spiral staircase, "if he put hermione whisper, a cart seemed to have had eaten for decoration," said harry. "i've heard the day somewhere in two; he could spear on  hagrid didn't keep putting the story started to be very fast, he seemed very nice, but he had to, in a slug. 17
-  "oh, shut up," said hagrid, glancing at the dark and then there wasn't going to look at the sofa on cats? after all. but clouds of course. hang around the snake just helping him as if they found a doorway to their mother would be laughed nervously. "you'll understand them, and immediately a few seconds, the dark red as still staring

As you can see from these examples, the generated text is recognisable as being from Harry Potter, and is breifly coherent at points, but is mainly nonsense. This is due to the fact that this uses a first order Markov Chain, meaining the probability of the next state is determined entirly by the current state. After seeing these results, I thought that using an input sampling containing shorter bursts of text (i.e. Tweets) may provide a better result. 

### Example 2
In this example, I've compiled a document containing ~50 tweets from the twitter account @realDonaldTrump.
I then aggregated a selection of output strings generated from this text sample.
- wasn't interested in court, the opinion of my election day, the media, in numerous cases, planned out of some fake ne i haveon edge again. get job very good talks!
- bad "dudes" out of our country to the election. sorry, people want border wall will be abused and killed yesterday in paris. tourists were the obama had with bad "dudes" out of
- iran is going crazy - yet obama too soft on @foxnews concerning immigrants from seven suspect countries." (wt)  so many mistakes made up a homeland security and so high, is fake
-  thank you in the first meeting jeff sessions visited the strongest consecutive months for him, or failure of the strongest consecutive months for eight years russia "ran over" president obama.
-  my "wires tapped" in the real scandal here in the real scandal here is working out by the white house correspondents' association dinner this is broken!



