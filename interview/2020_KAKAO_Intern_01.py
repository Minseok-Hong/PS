map = [(1,3), (0,0), (1,0), (2,0), (0,1), (1,1), (2,1), (0,2), (1,2), (2,2), (0,3), (2,3)]

def solution(numbers, hand):
    answer = ''
    lastleft = 10
    lastright = 11
    for i in range(len(numbers)):
        i = numbers[i]
        if i % 3 == 2 or i == 0:
            Lfar = abs(map[lastleft][0] - map[i][0]) + abs(map[lastleft][1] - map[i][1])
            Rfar = abs(map[lastright][0] - map[i][0]) + abs(map[lastright][1] - map[i][1])
            far = Rfar - Lfar
            if far == 0:
                if hand == "right":
                    answer += 'R'
                    lastright = i
                else:
                    answer += 'L'
                    lastleft = i  
            elif far > 0 :
                answer += 'L'
                lastleft = i
            elif far < 0:
                answer += 'R'
                lastright = i
        elif i % 3 == 1:
            answer += 'L'
            lastleft = i
        elif i % 3 == 0:
            answer += 'R'
            lastright = i
        
    return answer