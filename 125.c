bool isPalindrome(char * s){
    int len, flag;

    len = strlen(s);
    flag=1;
    if(len==1) return 1;
    
    for(int i=0, k=len-1; i<=k;i++,k--){
        flag =1;
        char sym1, sym2;
        sym1 = sym2 = -1;
        while(flag && i<=k){
            if(s[i]>='A' && s[i]<= 'Z'){
                sym1 = s[i] + 'a' - 'A';
                flag = 0;
            }else if(s[i]>='a' && s[i]<='z'){
                sym1 = s[i];
                flag = 0;
            }else if(s[i]>='0' && s[i]<='9'){
                sym1 = s[i];
                flag = 0;
            }else{
                i++;
            }
        } 
        flag = 1;
        while(flag && i<=k){
            if(s[k]>='A' && s[k]<= 'Z'){
                sym2 = s[k] + 'a' - 'A';
                flag = 0;
            }else if(s[k]>='a' && s[k]<='z'){
                sym2 = s[k];
                flag = 0;
            }else if(s[k]>='0' && s[k]<='9'){
                sym2 = s[k];
                flag = 0;
            }else{
                k--;
            }
        }
        if(sym1 != sym2) return 0;
    }
    
    return 1;
}