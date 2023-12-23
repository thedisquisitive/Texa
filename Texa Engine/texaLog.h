#pragma once

constexpr auto LOG_LEVEL = 4;
/*
0: No logging
1: Errors only to log, no terminal output
2: Print errors to terminal and log
3: Print everything to log, only errors to terminal
4: Print everything to terminal and log
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace Texa {
	namespace Logging {
		class TexaLog {
		private:
			string outFile, errorFile;
			ofstream stdOut, stdError;
		public:
			TexaLog() {
				outFile = "texa_stdout.log";
				errorFile = "texa_error.log";
				stdOut.open(outFile.c_str());
				stdError.open(errorFile.c_str());
				stdOut << "TexaLog object created.\n";
				stdError << "TexaErrorLog object created.\n";
				stdOut.close();
				stdError.close();
			}
			~TexaLog() {

			}

			void initDefault() {
				outFile = "texa_stdout.log";
				errorFile = "texa_error.log";
				stdOut.open(outFile.c_str());
				stdError.open(errorFile.c_str());
				stdOut << "TexaLog object created.\n";
				stdError << "TexaErrorLog object created.\n";
				stdOut.close();
				stdError.close();
			}

			// Write a line to stdOut
			void printStdOut(string s) {
				if (LOG_LEVEL >= 3) {
					stdOut.open(outFile.c_str(), ios::app);
					stdOut << s << "\n";
					stdOut.close();
				}
				if (LOG_LEVEL == 4) {
					cout << s << "\n";
				}
			}

			void printStdError(string s) {
				if (LOG_LEVEL >= 1) {
					stdError.open(errorFile.c_str(), ios::app);
					stdError << s << "\n";
					stdError.close();
				}
				if (LOG_LEVEL >= 2) {
					cout << s << "\n";
				}
			}

			void operator<<(string s) {
				printStdOut(s);
			}

			void operator>>(string s) {
				printStdError(s);
			}
		};
		
	}
}