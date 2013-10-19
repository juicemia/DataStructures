#!/usr/bin/python
import sys, math, time, string

# Changes from the seventh version:
# - Updated file reading
# - wordsFromLine function renamed to wordsFromText
# - extractWords function removed

# Document class to manipulate all the information
class Document():
    
    def __init__(self, filename):
        self.filename = filename; # filename of the document
        self.readFile()
        self.countFrequency()
    def readFile(self):
        file = open(self.filename, 'r')
        # no need to read file line by line
        self.wordlist = self.wordsFromText(file.read())
        file.close()
    def wordsFromText(self, text):
        # The two lines below converts all the punctuation into spaces
        # and all the uppercase characters to the lower case characters
        translation_table = string.maketrans(string.punctuation + string.uppercase, " "*len(string.punctuation) + string.lowercase)
        text = text.translate(translation_table)
        
        return text.split() # returns an array of words, split at spaces
    def countFrequency(self):
        self.ct_list = {} # dictionary of the words + count
        for word in self.wordlist:
            if word in self.ct_list:    # if word already exists
                self.ct_list[word] += 1 # update the counter
            else:                       # else, set the counter to 1
                self.ct_list[word] = 1
    @staticmethod
    def calculateVectorAngle(doc1, doc2):
        # equation for the angle is : arccos(L1*L2/|L1||L2|), 
        # and the length of the vector is |L1| = sqrt(L1*L1)
        numerator = Document.calculateDotProduct(doc1, doc2)
        denominator = math.sqrt(Document.calculateDotProduct(doc1, doc1) * Document.calculateDotProduct(doc2, doc2))
        return math.acos(numerator/denominator)
    def getWordlist(self):
        return self.ct_list
    @staticmethod
    def calculateDotProduct(doc1, doc2):
        # static function
        list1 = doc1.getWordlist()
        list2 = doc2.getWordlist()
        sum = 0
        
        # No need to iterate throught the second dictionary,
        # since if the elements existed in the first dictionary
        # they would've already been accounted for
        for key in list1: 
            if key in list2:
                sum += list1[key]  * list2[key]
                
        return sum
def main():
    if (len(sys.argv) != 3):
        print "Usage: python doc_distance_8.py textfile1 textfile2"
    else:
        doc1 = Document(sys.argv[1])
        doc2 = Document(sys.argv[2])
        print "The documents have the similarity of %0.6f radians" % Document.calculateVectorAngle(doc1, doc2)

# The way this works is, the closer to 0 degrees the documents are, the more similar they are.
# The closer to  90 degrees they are, the more different they are
# 0 deg = 0 rad, 90 deg = pi/2 rad ~ 1.57

#timers to measure running time
t0 = time.clock()
main()
t = time.clock()
print "It took %d seconds to run the algorithm" % (t - t0)

# time to finish sample info - 0 seconds
