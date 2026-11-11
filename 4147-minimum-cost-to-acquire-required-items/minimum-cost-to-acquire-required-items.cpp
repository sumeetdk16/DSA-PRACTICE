class Solution {
public:
    typedef long long ll;

    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Case A: bundle is costlier than buying item separately
        if (cost1 + cost2 <= costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        // Case B: bundle is better
        // Buy bundles as much as you can
        int bothitem = min(need1, need2);

        ll totalcost = 1LL * bothitem * costBoth;

        need1 -= bothitem;
        need2 -= bothitem;

        // Pending ones
        if (need1)
            totalcost += 1LL * need1 * min(cost1, costBoth);
        else if (need2)
            totalcost += 1LL * need2 * min(cost2, costBoth);

        return totalcost;
    }
};