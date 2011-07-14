#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TheBoringStoreDivTwo {
    public:
        string find(string X, string Y) {
            string ret = "";
            for (int i = 0; i < X.size(); ++i) {
                for (int j = i+1; j < X.size(); ++j) {
                    //A
                    string A = X.substr(i, j-i);
                    for (int k = 0; k < i; ++k) {
                        for (int l = k+1; l < i; ++l) {
                            //B
                            string B = X.substr(k, l-k);
                            for (int a = 0; a < Y.size(); ++a) {
                                for (int b = a+1; b < Y.size(); ++b) {
                                    //C
                                    string C = Y.substr(a, b-a);
                                    for (int c = 0; c < a; ++c) {
                                        for (int d = c+1; d < a; ++d) {
                                            //D
                                            string D = Y.substr(c, d-c);
                                            if (!A.empty() && !B.empty() && !C.empty() && !D.empty()) {
                                                if (A+C == B+D) {
                                                    string tmp = A+C;
                                                    if (tmp.size() > ret.size() || tmp.size() == ret.size() && tmp < ret) {
                                                        ret = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    for (int c = b; c < Y.size(); ++c) {
                                        for (int d = b+1; d < Y.size(); ++d) {
                                            //D
                                            string D = Y.substr(c, d-c);
                                            if (!A.empty() && !B.empty() && !C.empty() && !D.empty()) {
                                                if (A+C == B+D) {
                                                    string tmp = A+C;
                                                    if (tmp.size() > ret.size() || tmp.size() == ret.size() && tmp < ret) {
                                                        ret = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    for (int k = j; k < X.size(); ++k) {
                        for (int l = k+1; l < X.size(); ++l) {
                            //B
                            string B = X.substr(k, l-k);
                            for (int a = 0; a < Y.size(); ++a) {
                                for (int b = a+1; b < Y.size(); ++b) {
                                    //C
                                    string C = Y.substr(a, b-a);
                                    for (int c = 0; c < a; ++c) {
                                        for (int d = c+1; d < a; ++d) {
                                            //D
                                            string D = Y.substr(c, d-c);
                                            if (!A.empty() && !B.empty() && !C.empty() && !D.empty()) {
                                                if (A+C == B+D) {
                                                    string tmp = A+C;
                                                    if (tmp.size() > ret.size() || tmp.size() == ret.size() && tmp < ret) {
                                                        ret = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    for (int c = b; c < Y.size(); ++c) {
                                        for (int d = b+1; d < Y.size(); ++d) {
                                            //D
                                            string D = Y.substr(c, d-c);
                                            if (!A.empty() && !B.empty() && !C.empty() && !D.empty()) {
                                                if (A+C == B+D) {
                                                    string tmp = A+C;
                                                    if (tmp.size() > ret.size() || tmp.size() == ret.size() && tmp < ret) {
                                                        ret = tmp;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return ret;
        }
};
