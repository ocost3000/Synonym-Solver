def cosine_similarity(vec1, vec2):
    """This function returns the cosine similarity between the sparse vectors vec1 and vec2, stored as dictionaries."""


def build_semantic_descriptors_from_files(filenames):
    """
    This function takes a list of 'filenames' of strings, which contains the names of files (the first one can
    be opened using 'open(filenames[0], "r", encoding="utf-8") ), and returns a dictionary of the semantic
    descriptors of all the words in the files 'filenames', with the files treated as a single text.

    You should assume that the following punctuation always separates sentences: ".", "!", "?", and that is the
    only punctuation that separates sentences. You should assume that only the following punctuation is present
    in the texts: [’,’, ’-’, ’--’, ’:’, ’;’, ’"’, "’"]
    """



# ------------------------------------------INTERMEDIATE VERSON----------------------------------------------

# Part A
def get_sentence_list(text):
    """
    This function takes in a stirng 'text' and returns a list which contains lists of strings, one list
    for each sentence (as defiend below) in the string 'text'. A list representing a sentence is a list of
    the individual words in the sentence, each one in all-lowercase.

    For our purposes, sentences are separated by one of hte strings ".", "?", or "!". We ignore the
    possibility of other punctuation separating sentences. We also assume htat every period separates
    sentences.

    The words in the list that represents the sentence must be in the order in which they appear in the
    sentence, and must not being or end with punctuation.

    You should assume that only the following punctuation signs are present in the text file:
    ",", "-", "--", ":", "!", "?", ".", the single quote or the double quote.
    That the single quote is considered punctuation means that, for example, "don't" is considered to be two
    words: 'don' and 't'. The possessive from 'School's' is also considered to be two words: 'School" and "s"


        For example, if the text file contains the following (and nothing else):
            Hello, Jack.  How is it going?  Not bad; pretty good, actually...  Very very good, in fact.

        then the function should return the following list:
            [
                [’hello’, ’jack’],[’how’, ’is’, ’it’, ’going’],
                [’not’, ’bad’, ’pretty’, ’good’, ’actually’],
                [’very’, ’very’, ’good’, ’in’, ’fact’]
            ]


    """

# Part B
def get_sentence_list_from_files(filenames):
    """
    This funciton takes in a list of strings 'filenames', each one the name of a text file, and returns the
    list of every sentence ontained in all the text files in 'filenames', in order. The list is in the same
    format as in Part A, but with the files rather than a stirng serving as the source of text.
    """

# Part C
def build_semantic_descriptors(sentences):
    """
    This function takes in a list 'sentences' which contains lists of strings (words) representing sentences, 
    and returns a dictionary 'd' such that for every word 'w' that appears in at least one of the sentences,
    'd[w]' is itself a dictionary which represents the semantic descriptor of 'w'

    Example...
    """

# Part D
def most_similar_word(word, choices, semantic_descriptors):
    """
    This function takes in a string 'word', a list of strings 'choices', and a dictionary 'semantic_descriptons'
    which is built according to the requirements for 'build_semantic_descriptors', and returns the element of
    'choices' which has the largest semantic similarity to 'word', with the semantic similarity computed using
    the data in 'semantic_descriptors'. If the semantic similarity between two words cannot be computed, it
    is considered to be -1. In case of a tie between several elements in 'choices', the one with the smallest
    index in 'choices' should be returned (i.e. if htere is a tie between 'choices[5] and choices[7], then
    'choices[5] is returned).
    """

# Part E
def run_similarity_test(filename, semantic_descriptors):
    """This function takes in a string 'filename' which is the name of a file in the same format as 'test.txt'
    and returns the percentage (i.e. float between 0.0 and 100.0) of questions on which most_similar_word()
    gueses the answer correctly using the semantic descriptors stored in 'semantic_descriptors'
    
    The format of 'test.txt' is as follows. On each line, we are given a word (all lowercase), the correct
    answer, and the choices. For example, the line:

            feline cat dog cat horse

    Represents the question:

            feline:
            (a) cat
            (b) dog
            (c) horse

    and indicates that the correct answer is "cat"
    """