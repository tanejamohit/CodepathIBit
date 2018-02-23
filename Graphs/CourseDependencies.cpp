struct Course {
    int id;
    unordered_set<int> preRequisites;
    vector<int> preRequisiteFor;
    Course(int id): id(id) {
        
    }
};

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<Course> courses;
    vector<Course> fulfilledCourses;
    
    for (int i = 0; i <= A; i++) {
        courses.push_back(Course(i));
    }
    
    // Processing courses
    for (int i = 0; i < B.size(); i++) {
        courses[C[i]].preRequisites.insert(B[i]);
        courses[B[i]].preRequisiteFor.push_back(C[i]);
    }
    
    // Find courses which have no pre-requisites
    for (int i = 1; i <= A; i++) {
        if (courses[i].preRequisites.size() == 0) {
            fulfilledCourses.push_back(courses[i]);
        }
    }

    for (int i = 0; i < fulfilledCourses.size(); i++) {
        for (int j = 0; j < fulfilledCourses[i].preRequisiteFor.size(); j++) {
            int preReqCourseId = fulfilledCourses[i].preRequisiteFor[j];
            courses[preReqCourseId].preRequisites.erase(fulfilledCourses[i].id);
            if (courses[preReqCourseId].preRequisites.size() == 0) {
                fulfilledCourses.push_back(courses[preReqCourseId]);
            }
        }
    }
    
    return fulfilledCourses.size()==A?1:0;
}
