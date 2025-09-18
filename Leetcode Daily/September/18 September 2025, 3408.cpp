class TaskManager {
public:
    unordered_map<int, int> to; // taskId -> userId
    unordered_map<int, int> tp; // taskId -> priority
    priority_queue<pair<int, int>> pq; // {priority, taskId}

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &it : tasks) {
            pq.push({it[2], it[1]});
            to[it[1]] = it[0];
            tp[it[1]] = it[2];
        }
    }

    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        to[taskId] = userId;
        tp[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        if (tp.find(taskId) == tp.end()) return; // task not found
        tp[taskId] = newPriority;
        pq.push({newPriority, taskId}); // push updated version
    }

    void rmv(int taskId) {
        tp.erase(taskId);
        to.erase(taskId);
        // lazy removal (entry stays in pq but will be ignored later)
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            if (tp.find(taskId) != tp.end() && tp[taskId] == priority) {
                int ans = to[taskId];
                rmv(taskId);
                return ans;
            }
            pq.pop(); // discard stale entry
        }
        return -1; // no tasks left
    }
};
