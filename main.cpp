// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 
// Participation ✅: 
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

const string MESSAGE_WELCOME = "Welcome to my Final Grade Calculator!";
const string MESSAGE_GOODBYE = "Thank you for using my Grade Calculator!";
const string MESSAGE_INSTRUCTIONS = 
  "Please enter the following information and I will calculate your \n"
  "Final Numerical Grade and Letter Grade for you!\n"
  "The number of assignments must be between 0 and 10.\n"
  "All scores entered must be between 0 and 4.";

const string ERROR_OUT_OF_RANGE = "ERROR;( Out of range.";

const string PROMPT_NUMBER_OF_ASSIGNMENTS = "Enter the number of assignments (0 to 10): ";
const string PROMPT_ENTER_SCORE = "Enter score ";
const string PROMPT_ENTER_MIDTERM_EXAM_SCORE = "Enter your midterm exam score: ";
const string PROMPT_ENTER_FINAL_EXAM_SCORE = "Enter your final exam score: ";

const string LABEL_NUMERIC_GRADE = "Your numeric grade is ";
const string LABEL_LETTER_GRADE = "Your letter grade is ";

const int MIN_ASSIGNMENT_COUNT = 0;
const int MAX_ASSIGNMENT_COUNT = 10;

const double MIN_SCORE = 0.0;
const double MAX_SCORE = 4.0;

const double ASSIGNMENTS_WEIGHT = 0.6;
const double EXAM_WEIGHT = 0.2;


// Function prototypes (if any)
void welcome();

// Read integers from the user. 
int readInt(string prompt);

// Reprompt until valid
int readIntInRangeInclusive(string prompt, int min, int max);

// Read all the scores from the user. 
// Any time you read a score you must call this function. 
// The function must do data validation
//     It is a numeric value. 
//     It is within the range of 0 to 4 inclusive.
void readDouble(string prompt, double &num);

// Reprompt until valid
double readDoubleInInclusiveRange(string prompt, double min, double max);


// It is within the range of 0 to 4 inclusive.
double readScore(string prompt);

// Read the Assignment scores from the user. 
// This function must call readScore every time you read an Assignment score. 
// You must use a for loop to do this. 
// Calculate and return the average score.
double assignAverage(int numAssigns); 

// calls the readScore() function and 
// reads the 2 exam scores.
void getInput(double &midtermExamScore, double &finalExamScore);

// Takes 
//    Assignment average score, 
//    midterm exam score,
//    final exam score, 
// and calculates the final numerical score based on 
// Weights for assignments and exams. 
//    assignments are 60%, 
//    midterm exam    20%
//    final exam      20%
double calcDecimalGrade(double assignAvg, double midtermExamScore, double finalExamScore);

// A >= 3.3 <= 4.0 Exceeds
// B >= 2.8 <  3.3 Meets
// C >= 2.0 <  2.8 Approaching
// D >= 1.2 <  2.0 Not Yet
// F    0.0 <  1.2 No Evidence
void calcLetterGrade(double decimalGrade, char &letter); 

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {
  welcome();

  cout << MESSAGE_INSTRUCTIONS << endl;

  int assignmentCount = 
      readIntInRangeInclusive(PROMPT_NUMBER_OF_ASSIGNMENTS, 
                              MIN_ASSIGNMENT_COUNT, 
                              MAX_ASSIGNMENT_COUNT);

  double assignmentAverageScore = assignAverage(assignmentCount);
  double midtermExamScore = readScore(PROMPT_ENTER_MIDTERM_EXAM_SCORE);
  double finalExamScore = readScore(PROMPT_ENTER_FINAL_EXAM_SCORE);
  double decimalGrade = calcDecimalGrade(assignmentAverageScore, midtermExamScore, finalExamScore);

  cout << fixed << setprecision(1);
  cout << LABEL_NUMERIC_GRADE << decimalGrade << endl;
  
  char letterGrade = '\0';
  calcLetterGrade(decimalGrade, letterGrade);
  cout << LABEL_LETTER_GRADE << letterGrade << endl;

  return 0;
}

// Function implementations (if any)
// Function prototypes (if any)
void welcome() {
  cout << MESSAGE_WELCOME << endl;
}

// Read integers from the user. 
int readInt(string prompt) {
  int n = 0;
  bool next = true;
  while(next) {
    cout << prompt;
    cin >> n;
    if(cin) {
      next = false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << ERROR_OUT_OF_RANGE << endl;
    }
  }
  return n;
}

// Reprompt until valid
int readIntInRangeInclusive(string prompt, int min, int max) {
  int n = 0;
  bool next = true;
  while(next) {
    n = readInt(prompt);
    if(min <= n && n <= max) {
      next = false;
    } else {
      cout << ERROR_OUT_OF_RANGE << " [" << min << ", " << max << "]" << endl;
    }
  }
  return n;
}

// Read all the scores from the user. 
// Any time you read a score you must call this function. 
// The function must do data validation
//     It is a numeric value. 
//     It is within the range of 0 to 4 inclusive.
void readDouble(string prompt, double &n) {
  bool next = true;
  while(next) {
    cout << prompt;
    cin >> n;
    if(cin) {
      next = false;
    } else {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << ERROR_OUT_OF_RANGE << endl;
    }
  }
}

// Reprompt until valid
double readDoubleInInclusiveRange(string prompt, double min, double max) { 
  double n = 0;
  bool next = true;
  while(next) {
    readDouble(prompt, n);
    if(min <= n && n <= max) {
      next = false;
    } else {
      cout << ERROR_OUT_OF_RANGE << " [" << min << ", " << max << "]" << endl;
    }
  }
  return n;
}

// It is within the range of 0 to 4 inclusive.
double readScore(string prompt) {
  return readDoubleInInclusiveRange(prompt, MIN_SCORE, MAX_SCORE);
}

// Read the Assignment scores from the user. 
// This function must call readScore every time you read an Assignment score. 
// You must use a for loop to do this. 
// Calculate and return the average score.
double assignAverage(int numAssigns) {
  double average = 0.0;
  double sum = 0.0;

  for(int i = 1; i <=numAssigns; i++) {
    string s = PROMPT_ENTER_SCORE + to_string(i) + ": ";
    sum = sum + readScore(s);
  }

  average = sum / numAssigns;
  return average;
}





// calls the readScore() function and 
// reads the 2 exam scores.
void getInput(double &midtermExamScore, double &finalExamScore);

// Takes 
//    Assignment average score, 
//    midterm score,
//    final exam score, 
// and calculates the final numerical score based on 
// Weights for assignments and exams. 
//    assignments are 60%, 
//    midterm exam    20%
//    final exam      20%
double calcDecimalGrade(double assignAvg, double midtermExamScore, double finalExamScore) {
  return 
    assignAvg * ASSIGNMENTS_WEIGHT + 
    midtermExamScore * EXAM_WEIGHT + 
    finalExamScore * EXAM_WEIGHT;
}

// A >= 3.3 <= 4.0 Exceeds
// B >= 2.8 <  3.3 Meets
// C >= 2.0 <  2.8 Approaching
// D >= 1.2 <  2.0 Not Yet
// F    0.0 <  1.2 No Evidence
void calcLetterGrade(double decimalGrade, char &letter) {
  if(3.3 <= decimalGrade) {
    letter = 'A';
  } else if(2.8 <= decimalGrade) {
    letter = 'B';
  } else if(2.0 <= decimalGrade) {
    letter = 'C';
  } else if(1.2 <= decimalGrade) {
    letter = 'D';
  } else {
    letter = 'F';
  }
}


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type. 

B. OUTPUT
Define the output variables including data types. 

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS
Copy from assignment document.

*/
