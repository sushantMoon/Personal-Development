#
# Author : Sushant Moon
# Email : sushant.moon@gmail.com
# Date : 2018-10-10 00:04:37
# Description:  : 
# * http://community.topcoder.com/stat?c=problem_statement&pm=15012&rd=17259&rm=&cr=22716052
# * https://arena.topcoder.com/#/u/practiceCode/17261/67929/15012/1/331665
#
# logic : pbob(1-palice) = palice

class ShootingGame:
    def findProbability(self, p):
        pAlice = (p * 1.0) / 10**6
        pBob = pAlice / (1 - pAlice)
        if pBob >= 1:
            return -1
        return pBob