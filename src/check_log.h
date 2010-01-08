// Author: yi.wang.2005@gmail.com (Yi Wang)

#include <iostream>
#include <string>

// The CHECK_xxxx facilities, which generates a segmentation fault
// when a check is failed.  If the program is run within a debugger,
// the segmentation fault makes the debugger keeps track of the stack,
// which provides the context of the fail.
//
extern char* kSegmentFaultCauser;

#define CHECK(a) if (!(a)) {                                            \
    std::cerr << "CHECK failed "                                        \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \

#define CHECK_EQ(a, b) if (!((a) == (b))) {                             \
    std::cerr << "CHECK_EQ failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \

#define CHECK_GT(a, b) if (!((a) > (b))) {                              \
    std::cerr << "CHECK_GT failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \

#define CHECK_LT(a, b) if (!((a) < (b))) {                              \
    std::cerr << "CHECK_LT failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \

#define CHECK_GE(a, b) if (!((a) >= (b))) {                             \
    std::cerr << "CHECK_GE failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \

#define CHECK_LE(a, b) if (!((a) <= (b))) {                             \
    std::cerr << "CHECK_LE failed "                                     \
              << __FILE__ << ":" << __LINE__ << "\n"                    \
              << #a << " = " << (a) << "\n"                             \
              << #b << " = " << (b) << "\n";                            \
    *((char*)((unsigned long)kSegmentFaultCauser << 5)) = '\0';                \
  }                                                                     \
                                                                        \
                                                                        \
                                                                        \
  // The log facility, which makes it easy to leave of trace of your
// program.  The logs are classified according to their severity
// levels.  Logs of the level FATAL will cause a segmentation fault,
// which makes the debugger to keep track of the stack.
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
      *::kSegmentFaultCauser = '\0';
    }
  }
 private:
  LogSeverity ls_;
  std::string file_;
  int line_;
};

#define LOG(ls) Logger(ls, __FILE__, __LINE__).stream()
