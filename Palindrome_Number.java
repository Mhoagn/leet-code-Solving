class Palindrome {
    private long reverseNum(long x){
        long num = 0;
        while(x > 0){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }
    public boolean isPalindrome(long x) {
        if(x < 0 ) return false;
        else{
            return reverseNum(x) == x;
        }
    }
}
