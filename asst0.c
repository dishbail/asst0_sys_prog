#include <stdio.h>
#include<stdlib.h>

char ** delimSemiColon(char input[]){
        int i = 0;//loop iteration
        int temp = 0; //length of the longest  expression
        int count_colon = 0;//number of semi colons in the string
        while(input[i]!='\0'){//looping through the string array
                if(input[i] == ';'){
                        count_colon++;
                }
                i++;
                temp = i;
        }
        count_colon++; //because expressions = one plus semi colon
        char** stArr = malloc(count_colon*sizeof(char*));//allocate enough memory for expressions
        int j = 0; //while loop for populating the array of strings
        int b_Index = 0;
        while(input[j]!='\0'){//looping through the given string
                //find the index of the first semi colon = you know the number of colons, use this information to get to a solution
                //subtract it from the start
                stArr[b_Index] = malloc(temp*sizeof(char)); //allocating memory for the length of the string for each expression
                int hi_count = 0;
                while((input[j]!=';')&& input[j]!='\0'){
                        stArr[b_Index][hi_count] = input[j];
                        hi_count++;
                        j++;
                }
                stArr[b_Index][hi_count] = '\0';
                if (input[j] != '\0') {
                        j++;
                }
                b_Index++;
        }
        return stArr;
}

char ** delimSpace(char input[]){
        int i = 0;//loop iteration
        int temp = 0;//length of the token
        int count_space = 0;//number of spaces in the expression
        while(input[i]!='\0'){//looping through the expression
                if(input[i] == ' '){
                        count_space++;
                }
                i++; 
                 temp = i;
        }
        count_space++; //because typically expression = one plus the number of spaces
        char** wordArr = malloc(count_space*sizeof(char*));//allocate enough memory for the words in the expression
        int j = 0;
        int b_Index = 0;
        while(input[j]!='\0'){//looping through a given expression
                wordArr[b_Index] = malloc(temp*sizeof(char)); //allocating memory for the length of the string of each word
                int hi_count = 0;
                while(input[j]!=' '&& input[j]!='\0'){
                        wordArr[b_Index][hi_count] = input[j];
                        hi_count++;
                        j++;
                }
                if(wordArr[b_Index][hi_count] != '\0'){
                wordArr[b_Index][hi_count] = '\0';
                }
                if(input[j] != '\0'){
                        j++;
                }
                b_Index++;
        }
        return wordArr;
}
int strCompare(char* input1, char* input2){
        int i = 0;
        if( input1 == '\0' || input2 == '\0'){
                return 0;
        }
        while(input1[i] != '\0'){
                if(input1[i] != input2[i]){
                        return 0;
                }
                i++;
        }
        if(input2[i]!='\0'){
                return 0;
        }
        return 1;
}

char exprType(char** inputWords){
        int i = 0; //iterator for the while loop
        int counter = 0; //counter for the number of operators in the expression
        int a = 0; //counter for if it is a arithmetic operator
        int l = 0;   //counter for if it is a logical operator
        while(* (inputWords + i) != '\0'){//parses through the words of that expression
                char* word = *(inputWords + i);
                if(word != '\0'){
                        if((strCompare(word,"NOT") == 1)||(strCompare(word,"AND") == 1) || (strCompare(word,"OR") == 1)){
                                l++;
                                counter++;
                        }
                        if((strCompare(word,"+") == 1)||(strCompare(word,"-")==1) || (strCompare(word,"*")==1) || (strCompare(word,"/")==1)){
                                a++;
                                counter++;
                        }
                }
        if ((word+1)!= '\0'){
                i++;
                }
        else{
                break;
        }
        }
        if(counter == 0) { return 'n'; }//n for no operators
        if(counter > 1) {return 'e'; } //e for error in the expression because there are more than one operators
        if(counter == 1){
 if(a == 1) {
                        return 'a'; //a for arithmetic operator
                }
                else {
                        return 'l'; //l for logical operator
                }
        }
}



int main(int argc, char *argv[])
{
        char* input1 = "andfalse";
        char* input2 = "NOTtrues";
        printf("%d\n", strCompare(input1,input2));
        char* string = *(argv+1);
        char** stringArray = delimSemiColon(string);
        int stri = 0; //iterator for the expressions in the string //USE AS OUTPUT
        while(*(stringArray + stri) != '\0'){//parses through the expressions in the given string
                printf("%s\n", *(stringArray + stri));
                //check for a valid operator in the expression
                char** wordArray = delimSpace(*(stringArray + stri));
                char expType  = exprType(wordArray);
                //method for what kind of expression it is supposed to be
                //printf("%c\n", expType);
                //check whether it has the right operands
                int wordi = 0;//iterator for the words in the expression
                int validWord = 3; //int for the valid words in the expression
                while(* (wordArray + wordi) != '\0'){//parses through the words of that expression
                        //printf("%s\n", *(wordArray + wordi));
                        char* word = *(wordArray + wordi);



                        wordi++;
                        //int wordPtr = 0;
                        //while(* (wordArray + wordPtr) != '\0'){
                                //free(char*(wordArray + wordPtr));
                                //wordPtr++;
                        }
                        //free(char**wordArray);
                //}
                        stri++;
        }
int strPtr = 0;
        //while(*(stringArray + strPtr) != '\0'){//parses through the expression pointers
                //free(char*(stringArray + strPtr));
                //strPtr++;
        //}
        //free(char**stringArray);
        //printf("%s\n", *(argv+2));
        //char str[] = *(argv+1);
        //printf("%s\n", str);
        return 0;
}

