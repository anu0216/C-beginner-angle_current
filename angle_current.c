 #include <stdio.h>

// 각도에서 전류로 변환하는 함수
double calculate_current(double angle, double min_angle, double max_angle, double min_current, double max_current) {
    double current = min_current + ((max_current - min_current) / (max_angle - min_angle)) * (angle - min_angle);
    return current;
}

// 전류에서 각도로 변환하는 함수
double calculate_angle(double current, double min_angle, double max_angle, double min_current, double max_current) {
    double angle = min_angle + ((max_angle - min_angle) / (max_current - min_current)) * (current - min_current);
    return angle;
}

int main() {
    double angle_input, current_input;
    double current_output, angle_output;

    // 사용자 입력을 받아 각도에서 전류로 변환
    printf("각도를 입력하세요 (예: -30 ~ 30 사이): ");
    scanf("%lf", &angle_input);
    current_output = calculate_current(angle_input, -30, 30, 20, 4);
    printf("입력한 각도 %lf°에 대한 전류는 %lfmA 입니다.\n", angle_input, current_output);

    // 사용자 입력을 받아 전류에서 각도로 변환
    printf("전류를 입력하세요 (예: 4 ~ 20 사이): ");
    scanf("%lf", &current_input);
    angle_output = calculate_angle(current_input, -30, 30, 20, 4);
    printf("입력한 전류 %lfmA에 대한 각도는 %lf° 입니다.\n", current_input, angle_output);

    return 0;
}
