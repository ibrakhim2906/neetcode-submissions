class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:

        def get_sign(a, b):
            if a > b:
                return 1
            elif a < b:
                return -1
            return 0

        if len(arr) < 2:
            return len(arr)
        length = 1

        L = 0

        for R in range(1, len(arr)):
            sign1 = get_sign(arr[R - 1], arr[R])

            if sign1 == 0:
                L = R
            elif R < len(arr) - 1 and sign1 * get_sign(arr[R], arr[R + 1]) == -1:
                pass
            else:
                length = max(length, R - L + 1)
                L = R

        return length
