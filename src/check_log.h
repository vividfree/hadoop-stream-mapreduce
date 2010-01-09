// Author: yi.wang.2005@gmail.com (Yi Wang)

#include <iostream>
#include <string>

// The CHECK_xxxx facilities, which generates a segmentation fault
// when a check is failed.  If users has set
//     ulimit -u unlimited
// the segmentation fault will cause a core dump, which can later be
// used to print the stack trace using a debugger.
void GenerateSegmentationFault();


#define CHECK(a) if (!(a)) {                                            \
    std::cerr << "CHECK failed "                                        \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

#define CHECK_EQ(a, b) if (!((a) == (b))) {                             \
    std::cerr << "CHECK_EQ failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

#define CHECK_GT(a, b) if (!((a) > (b))) {                              \
    std::cerr << "CHECK_GT failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

#define CHECK_LT(a, b) if (!((a) < (b))) {                              \
    std::cerr << "CHECK_LT failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

#define CHECK_GE(a, b) if (!((a) >= (b))) {                             \
    std::cerr << "CHECK_GE failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

#define CHECK_LE(a, b) if (!((a) <= (b))) {                             \
    std::cerr << "CHECK_LE failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    GenerateSegmentationFault();					\
  }                                                                     \

// The log facility, which makes it easy to leave of trace of your
// program.  Log operations are classified by their severity levels.
// Logs of the level FATAL will cause a segmentation fault, which
// in turn leaves the chance to trace stack using a debugger.
//
// Examples:
//   LOG(INFO) << iteration << "-th iteration ...";
//   LOG(FATAL) << "Probability value < 0 " << prob_value;
//
enum LogSeverity { INFO, WARNING, ERROR, FATAL };

class Logger {
 public:
  Logger(LogSeverity ls, const std::string& file, int line)
      : ls_(ls), file_(file), line_(line)
  {}
  std::ostream& stream() const {
    return std::cerr << file_ << " (" << line_ << ") : ";
  }
  ~Logger() {
    if (ls_ == FATAL) {
      GenerateSegmentationFault();
    }
  }
 private:
  LogSeverity ls_;
  std::string file_;
  int line_;
};

#define LOG(ls) Logger(ls, __FILE__, __LINE__).stream()
