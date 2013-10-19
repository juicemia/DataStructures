#!/usr/bin/python
import sys, math, time, string

# Changes from the fourth version:
# - Modifed words from line method

# Document class to manipulate all the information
class Document():
    
    def __init__(self, filename):
        self.filename = filename; # filename of the document
        self.readFile()
        self.countFrequency()
        self.insertionSort()
    def readFile(self):
        file = open(self.filename, 'r')
        lines = []
        for line in file:
                lines.append(line.strip())
        file.close()
        self.extractWords(lines)
    def extractWords(self, lines):
        self.wordlist = []
        for l in lines:
            words = self.wordsFromLine(l)    # words in line
            self.wordlist.extend(words)
    def wordsFromLine(self, line):
        # The two lines below converts all the punctuation into spaces
        # and all the uppercase characters to the lower case characters
        translation_table = string.maketrans(string.punctuation + string.uppercase, " "*len(string.punctuation) + string.lowercase)
        line = line.translate(translation_table)
        
        return line.split() # returns an array of words, split at spaces
    def countFrequency(self):
        self.ct_list = {} # dictionary of the words + count
        for word in self.wordlist:
            if word in self.ct_list:    # if word already exists
                self.ct_list[word] += 1 # update the counter
            else:                       # else, set the counter to 1
                self.ct_list[word] = 1
        self.ct_list = self.ct_list.items() # returns the dictionary into 2d array
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
        i, j = (0, 0)
        
        while (i < len(list1) and j < len(list2)):
            if (list1[i][0] == list2[j][0]):
                # both lists contain the word
                sum += list1[i][1] * list2[j][1]
                i+=1
                j+=1
            elif (list1[i][0] < list2[j][0]):
                # word is in list1 but not in list2, since the list
                # is sorted, and list2 being higher, yields that
                # larger valued string is in there
                i+=1
            else:
                # word is in list2 but not in list1
                j+=1
        return sum
    def insertionSort(self):
        # simple insertion sort algorithm
        for i in range(len(self.ct_list)):
            key = self.ct_list[i]
            j = i - 1
            while (j>-1 and self.ct_list[j]>key):
                self.ct_list[j+1] = self.ct_list[j]
                j-=1
            self.ct_list[j] = key
def main():
    if (len(sys.argv) != 3):
        print "Usage: python doc_distance_5.py textfile1 textfile2"
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

# time to finish sample info - 267 seconds