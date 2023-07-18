#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   
    
//=========Question 1==================================
	void TestQ1_strlen_case1(CuTest *tc)
	{
		char str[] = "This is a test!";
		int expected = 15;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}
	
	void TestQ1_strlen_case2(CuTest *tc)
	{
		char str[] = "This is another test...";
		int expected = 23;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strlen_case0(CuTest *tc)
	{
		char str[] = "";
		int expected = 0;
		int actual = 0;

		actual = my_strlen(str);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseEqual(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test!";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalLength(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a test! ";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseUnequalContents(CuTest *tc)
	{
		char str1[] = "This is a test!";
		char str2[] = "This is a pass!";
		int expected = 0;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmp_caseEmpty(CuTest *tc)
	{
		char str1[] = "";
		char str2[] = "";
		int expected = 1;
		int actual = 0;

		actual = my_strcmp(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSmaller(CuTest *tc)
	{
		char str1[] = "Absolutely";
		char str2[] = "new start";
		int expected = 0;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseLarger(CuTest *tc)
	{
		char str1[] = "more than";
		char str2[] = "an apple";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSame(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Content";
		int expected = -1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}

	void TestQ1_strcmpOrder_caseSomewhatDiff(CuTest *tc)
	{
		char str1[] = "Timeless Content";
		char str2[] = "Timeless Contents";
		int expected = 1;
		int actual = 0;

		actual = my_strcmpOrder(str1, str2);

		CuAssertIntEquals(tc, expected, actual);
	}
	
	void TestQ1_strcat_TwoStrings(CuTest *tc) 
	{
		char str_expected[] = "HelloWorld!";
		char str1[] = "Hello";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_FirstEmpty(CuTest *tc) 
	{
		char str_expected[] = "World!";
		char str1[] = "";
		char str2[] = "World!";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

	void TestQ1_strcat_SecondEmpty(CuTest *tc) 
	{
		char str_expected[] = "Hello";
		char str1[] = "Hello";
		char str2[] = "";
		char* str_actual = my_strcat(str1, str2);
		
		CuAssertStrEquals(tc, str_expected, str_actual);

		free(str_actual);
	}

/*	

    
//===========================================================
//=================Question 2================================
	void TestQ2_find_notThere(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = -1;
		int actual = find(0011,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

	}

	void TestQ2_find_There(CuTest *tc) {

		char inputFile[] =  "students.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);

		int expected = 4;
		int actual = find(9000,Clist,size);

		CuAssertIntEquals(tc, expected, actual);

	}

	void TestQ2_inputGradesAndCalculateFinal(CuTest *tc) {

		

		char inputFile[] =  "students.txt";
		char gradesFile[] =  "grades.txt";
		int size;
		//create list using the input file
		student **Clist = create_class_list(inputFile,&size);
		//input grades using the grades input file
		input_grades(gradesFile,Clist,size);
		//calculate final grades
		compute_final_course_grades(Clist,size);
		//Output final course marks
		output_final_course_grades("outputGrades.txt",Clist,size);

		//now we open the golden file with the written file and compare line by line

		char actualFile[] =  "outputGrades.txt";
		char goldenFile[] =  "output.txt";

		char actual[1000], expected[1000];
		int actualID,expectedID;
		double actualFinalGrade,expectedFinalGrade;
		FILE *actualPtr, *expectedPtr;
		if ((actualPtr = fopen(actualFile, "r")) == NULL || (expectedPtr = fopen(goldenFile, "r")) == NULL) {
			printf("Error! opening file");
			// Program exits if file pointer returns NULL.
			exit(1);
		}

		int actualNumStudents,expectedNumStudents;


		fscanf(actualPtr,"%d",&actualNumStudents);
		
		fscanf(expectedPtr,"%d",&expectedNumStudents);
		
		CuAssertIntEquals(tc, expectedNumStudents, actualNumStudents);

		int i;
		for(i=0;i<expectedNumStudents;i++){
		//while (actualPtr != NULL && expectedPtr!=NULL){
			// reads text until newline is encountered
			//fscanf(actualPtr, "%[^\n]", actual);
			//printf("%s ", actual);
			//fscanf(expectedPtr, "%[^\n]", expected);
			//printf("%s\n", expected);

			//CuAssertStrEquals(tc, expected, actual);

		
			fscanf(actualPtr,"%d",&actualID);
			
			fscanf(expectedPtr,"%d",&expectedID);
			
			CuAssertIntEquals(tc, expectedID, actualID);

			fscanf(actualPtr,"%lf",&actualFinalGrade);
			fscanf(expectedPtr,"%lf",&expectedFinalGrade);
			CuAssertDblEquals(tc, expectedFinalGrade, actualFinalGrade,0.000001);
		}
		if ((actualPtr == NULL && expectedPtr!=NULL)|| (actualPtr != NULL && expectedPtr==NULL)){

			printf("files are not of equal size");
			// Program exits if file pointer returns NULL.
			exit(1);

		}

	}

//===========================================================
//=================Question 3================================  
	void TestQ3_readandSort1(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};
		
		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
   
	void TestQ3_readandSort2(CuTest *tc) {

		char inputFile[] =  "wordlist.txt";
		int size;
		//create list using the input file
		char **actualList = read_words(inputFile,&size);
		sort2_words(actualList,size);

		char *expectedList[]={"apple","banana","hello","milan","programming","zebra"};

		

		int i;
		for (i=0;i<size;i++)
			CuAssertStrEquals(tc, expectedList[i], actualList[i]);

	}
 
*/

	

//===========================================================
	CuSuite* Lab3GetSuite() {

		CuSuite* suite = CuSuiteNew();

		SUITE_ADD_TEST(suite, TestQ1_strlen_case1); 
		SUITE_ADD_TEST(suite, TestQ1_strlen_case2);
		SUITE_ADD_TEST(suite, TestQ1_strlen_case0);

		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEqual);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalLength); 
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseUnequalContents);
		SUITE_ADD_TEST(suite, TestQ1_strcmp_caseEmpty);

		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSmaller);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseLarger); 
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSame);
		SUITE_ADD_TEST(suite, TestQ1_strcmpOrder_caseSomewhatDiff);

		SUITE_ADD_TEST(suite, TestQ1_strcat_TwoStrings); 
		SUITE_ADD_TEST(suite, TestQ1_strcat_FirstEmpty);
		SUITE_ADD_TEST(suite, TestQ1_strcat_SecondEmpty);

//		SUITE_ADD_TEST(suite, TestQ3_readandSort1);
//		SUITE_ADD_TEST(suite, TestQ3_readandSort2);
        
       

		return suite;
	}
    
