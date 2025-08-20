class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> events;

    for (const auto& meeting : meetings) {
        int start = meeting[0];
        int end = meeting[1];
        events.emplace_back(start, 1);     
        events.emplace_back(end + 1, -1);
    }

    // Sort events by the day
    sort(events.begin(), events.end());

    int freeDays = 0;
    int ongoingMeetings = 0;
    int previousDay = 1;

    for (const auto& event : events) {
        int currentDay = event.first;
        int change = event.second;

        // If there are no ongoing meetings, count the free days between previous day and current day
        if (ongoingMeetings == 0) {
            freeDays += currentDay - previousDay;
        }
        
        // Update the number of ongoing meetings
        ongoingMeetings += change;
        
        // Update previous day to current day
        previousDay = currentDay;
    }

    // Handle the days after the last event till the end of given days
    if (ongoingMeetings == 0) {
        freeDays += days - previousDay + 1;
    }

    return freeDays;
    }
};
