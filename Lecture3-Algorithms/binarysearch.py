class BSearch:
    def __init__(self, arr, targetnum):
        self.arr = arr
        self.targetnum = targetnum

        arr = [1,2,3,4,5,6,7,8,9,10,11,12,13]
        targetnum = 10

    def binarysearch(self, arr, targetnum):
        middle = len(arr)/2
        if arr[middle] == targetnum:
            return true
        elif arr[middle] < targetnum:
            return self.binarysearch(arr[:middle], targetnum)
        elif arr[middle] > targetnum:
            return self.binarysearch(arr[middle:], targetnum)
        else:
            return false