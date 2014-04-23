

def MSS( arr ):
    start = end = maxSum = currSum = seqStart = seqEnd = 0

    for i in range(len(arr)):
        currSum = currSum + arr[i]

        if currSum > maxSum:
            maxSum = currSum
            seqStart = start
            seqEnd = i
        elif currSum < 0:
            start = i + 1
            currSum = 0

    print "Sum: ", maxSum, "  Start: ", seqStart, "  End: ", seqEnd
            


arr = [-3,-4,-5,-2,-9,-6,-6,-12,-8,-2,-20,-6,-6,-12,-9]
MSS(arr)
