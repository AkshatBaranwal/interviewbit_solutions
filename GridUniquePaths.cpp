// https://www.interviewbit.com/problems/grid-unique-paths/
int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // Solution 1 (concise solution)
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = B; i < (A + B - 1); i++) {
        ans *= i;
        ans /= (i - B + 1);
    }
    return (int)ans;
    
}