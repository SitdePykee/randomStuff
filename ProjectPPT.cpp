#include <stdio.h>
#include <math.h>

float phuongTrinh(float heSo[], int bac, float x) {
    float ketQua = 0.0;
    for (int i = 0; i <= bac; i++) {
        ketQua += heSo[i] * pow(x, i);
    }
    return ketQua;
}

float chiaDoi(float heSo[], int bac, float a, float b, float epsilon) {
    float c;
    float fa = phuongTrinh(heSo, bac, a);
    float fb = phuongTrinh(heSo, bac, b);

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;
        float fc = phuongTrinh(heSo, bac, c);
        if (fabs(fc) == 0) {
            break;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return c;
}

void khuGauss() {
    int size;
    printf("Nhap kich thuoc ma tran: ");
    scanf("%d", &size);
    double mtr[size][size + 1];
    int i, j, k;

    printf("\nNhap ma tran he so:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Nhap phan tu A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &mtr[i][j]);
        }
    }

    printf("\nNhap ma tran ket qua:\n");
    for (i = 0; i < size; i++) {
        printf("Nhap phan tu B[%d]: ", i + 1);
        scanf("%lf", &mtr[i][size]);
    }

    // Bước khử Gauss
    for (k = 0; k < size - 1; k++) {
        // Chọn pivot: phần tử chính đường chéo của hàng hiện tại (mtr[k][k])
        double pivot = mtr[k][k];

        for (i = k + 1; i < size; i++) { //vòng lặp qua các hàng phía dưới hàng pivot. Chúng ta bắt đầu từ hàng k+1 và kết thúc ở hàng cuối cùng.
            // Tính tỉ lệ (ratio): hệ số được tính toán để trừ đi bội số của hàng pivot từ các hàng khác
            double ratio = mtr[i][k] / pivot;   //tính toán ratio bằng cách chia phần tử hiện tại của hàng dưới pivot cho giá trị của pivot.
            for (j = k; j < size + 1; j++) {    // Lấy giá trị hiện tại của hàng dưới pivot trừ đi tích của ratio và giá trị tương ứng của hàng pivot, mục đích để đưa các phần tử dưới pivot = 0
                mtr[i][j] -= ratio * mtr[k][j];
            }
        }
    }   //Sau khi hoàn thành vòng lặp, ma trận hệ số đã được biến đổi để đưa về dạng tam giác.

    // Tính nghiệm
    double solution[size];
    solution[size - 1] = mtr[size - 1][size] / mtr[size - 1][size - 1];
    for (i = size - 2; i >= 0; i--) {
        double sum = mtr[i][size];
        for (j = i + 1; j < size; j++) {
            sum -= mtr[i][j] * solution[j];
        }
        solution[i] = sum / mtr[i][i];
    }

    // Hiển thị nghiệm
    printf("\nNghiem cua he phuong trinh:\n");
    for (i = 0; i < size; i++) {
        printf("x[%d] = %.2lf\n", i, solution[i]);
    }
}


void luaChon() {
    int choice;
    while (1) {
        printf("\nChon phuong phap giai:\n");
        printf("1. Phuong phap chia doi\n");
        printf("2. Phuong phap khu Gauss\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1: {
                int bac;
                double a, b, epsilon;
                printf("Nhap so bac toi da (bac > 0): ");
                scanf("%d", &bac);
                while (bac < 0) {
                    printf("So bac khong hop le, nhap lai (bac > 0): ");
                    scanf("%d", &bac);
                }

                float heSo[bac + 1];
                for (int i = 0; i <= bac; i++) {
                    printf("He so cua bac %d: ", i);
                    scanf("%f", &heSo[i]);
                }
                printf("\n");

                printf("Gia tri a (a < b): ");
                scanf("%lf", &a);
                printf("Gia tri b (b > a): ");
                scanf("%lf", &b);

                float fa = phuongTrinh(heSo, bac, a);
                float fb = phuongTrinh(heSo, bac, b);

                while (fa * fb >= 0) {
                    printf("Khong dam bao dieu kien fa * fb < 0 trong khoang cho truoc.\n");
                    printf("Nhap lai gia tri a (a < b): ");
                    scanf("%lf", &a);
                    printf("Nhap lai gia tri b (b > a): ");
                    scanf("%lf", &b);
                    fa = phuongTrinh(heSo, bac, a);
                    fb = phuongTrinh(heSo, bac, b);
                }

                printf("Nhap gia tri EPSILON: ");
                scanf("%lf", &epsilon);
                printf("\n");

                float ketQua = chiaDoi(heSo, bac, a, b, epsilon);
                printf("Nghiem cua phuong trinh: %f\n", ketQua);

                return;
            }
            case 2:
                khuGauss();
                return;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }
}

int main() {
    luaChon();
    return 0;
}
