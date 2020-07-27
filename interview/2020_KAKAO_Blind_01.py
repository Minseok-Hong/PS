def solution(s):
    slen = len(s)
    answer = slen
    for token in range(1, slen//2 +1):
        loopcnt, start = 0, 0
        tmpret = slen
        firstloop = 0
        #print("[%d]=============="%token)
        while start + loopcnt*token < slen:
            #print("%s[%d:%d] : %s[%d:%d]" % (s[start:start + token],start,start + token, s[start + token:start + 2 * token],start + token,start + 2 * token))
            while s[start:start + token] == s[start + token:start + 2*token]:
                #print("\t%s[%d:%d] : %s[%d:%d]" % (s[start:start + token],start,start + token, s[start + token:start + 2 * token],start + token,start + 2 * token))
                if firstloop == 0 and start == 0:
                    firstloop += 1
                if firstloop:
                    loopcnt += 1
                    start += token
                #print("\t\tstart %d loop %d"%(start,loopcnt))
            if loopcnt:
                firstloop += 1
                start += token
                tmpret = (tmpret - loopcnt * token + 1)
            else:
                start += 1
            #print("tmpret : %d"%tmpret)
            loopcnt = 0
        answer = min(answer, tmpret)
    return answer

a = [
    "a",
    #"ababcdcdababcdcd",
    #"aabbaccc",
    #"abcabcdede",
    #"ababcdcdababcdcd",
    #"abcabcabcabcdededededede",
    #"xababcdcdababcdcd",
    #'aaaaaa',
]

for x in a:
    print(x)
    print(solution(x))