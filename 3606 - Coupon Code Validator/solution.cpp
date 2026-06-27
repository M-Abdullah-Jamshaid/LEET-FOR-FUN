class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        struct Coupon {
            string code;
            int businessPriority;
        };

        vector<Coupon> validCoupons;
        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (!isActive[i])
                continue;

            int priority = -1;
            if (businessLine[i] == "electronics")
                priority = 0;
            else if (businessLine[i] == "grocery")
                priority = 1;
            else if (businessLine[i] == "pharmacy")
                priority = 2;
            else if (businessLine[i] == "restaurant")
                priority = 3;

            if (priority == -1)
                continue;

            if (code[i].empty())
                continue;
            bool isCodeValid = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    isCodeValid = false;
                    break;
                }
            }
            if (!isCodeValid)
                continue;

            validCoupons.push_back({code[i], priority});
        }

        sort(validCoupons.begin(), validCoupons.end(),
             [](const Coupon& a, const Coupon& b) {
                 if (a.businessPriority != b.businessPriority) {
                     return a.businessPriority < b.businessPriority;
                 }
                 return a.code < b.code;
             });

        vector<string> result;
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.code);
        }

        return result;
    }
};