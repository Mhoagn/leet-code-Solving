int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    int pos = -1;
    for (int i = 0; i <= len1 - len2; i++) {
        char* str = (char*)malloc((len2 + 1) * sizeof(char)); 
        strncpy(str, haystack + i, len2); 
        str[len2] = '\0'; 
        if (!strcmp(str, needle)) { 
            pos = i;
            break;
        }
        free(str); 
    }
    return pos;
}
