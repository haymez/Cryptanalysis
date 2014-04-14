#-------------------------------------------#
#-------------------------------------------#
#This program deciphers text that has been
#ciphered using simple substitution without
#removing spaces.
#-------------------------------------------#
#-------------------------------------------#

import sys

#Must have two arguments
if len(sys.argv) != 2:
    print "USAGE: python crypto.py CIPHER_WORD"
    exit()

#Returns the pattern of a given word
def getPattern(word):
    patCount = 0
    pattern = ""
    
    #Strip any non-alphabetical characters from word
    for i in range(len(word)):
        letter = word[i:i+1]
        if letter.isalpha() is False:
            word = word[:i] + word[i+1:]
    
    #Creates pattern string
    for i in range(len(word)):
        letter = word[i:i+1]
        loc = word[:i].find(letter)
        if loc == -1:
            pattern += str(patCount)
            patCount += 1
        else:
            pattern += str(loc)
    return pattern

dict = open('/usr/share/dict/american-english')
words = dict.readlines()
pattern = getPattern(sys.argv[1])

#Enumerate dictionary file and test each word's pattern against the given pattern
for i, line in enumerate(words):
    if len(pattern) == len(getPattern(words[i])):
        if pattern == getPattern(words[i]):
            print "Try " + words[i]

dict.close()



#~ HEWFNUXEYHC XS AHNOLFOB WYH ZURNFU XSAROTFWXRS FEELOFSDH DHOWXAXDFWXRS 
#~ ZXFD QORZOFT XE F OXZRORLE QORZOFT CHEXZSHC WR HSELOH WYFW EHDLOXWB 
#~ QORAHEEXRSFUE THHW F TXSXTLT EWFSCFOC RA HIDHUUHSDH XS WYH VSRJUHCZH 
#~ FSC EVXUUE WYHB QREEHEE WYHOH XE F DOXWXDFU EYROWFZH RA XSAROTFWXRS 
#~ EHDLOXWB QORAHEEXRSFUE XS WYH XSCLEWOB WRCFB TFSB RA WYREH HSWOLEWHC 
#~ JXWY EHDLOXWB OHEQRSEXNXUXWXHE YFKH SRW OHDHXKHC WYH WOFXSXSZ SHDHEEFOB 
#~ WR CR WYHXO MRNE ZXFD DHOWXAXDFWXRS HSFNUHE WYREH XS WYH EHDLOXWB 
#~ XSCLEWOB WR CHTRSEWOFWH WYH CHQWY RA WYHXO FNXUXWB FSC FEELOH DLOOHSW 
#~ RO QOREQHDWXKH HTQURBHOE WYFW WYH DHOWXAXHC XSCXKXCLFU YFE WYH FNXUXWB 
#~ WR ELDDHHC
