## Đặt bài toán 

- Phần cứng:
    + Một nút bấm (sử dụng nút BOOT có sẵn trên board).
    + Một đèn LED rời bên ngoài gắn vào chân GPIO chỉ định (qua điện trở hạn dòng 220Ω).
- Yêu cầu chức năng:
    + Nhấn nút một lần (single click): Bật/Tắt LED (đảo trạng thái).
    + Nhấp đúp (double click): Chuyển sang chế độ nhấp nháy liên tục (chu kỳ 200ms).
    + Nếu tiếp tục nhấn single click: Dừng nháy và quay lại trạng thái Bật/Tắt bình thường.
    + Khử rung phím bấm tự động thông qua thư viện.

## Mục đích DEMO

Project sử dụng thư viện `OneButton` và thư viện hướng đối tượng `LED.h` tự viết:
- `OneButton` (tác giả Matthias Hertel): Xử lý các sự kiện click, double click và chống rung phím.
- `LED.h`: Cung cấp API trực quan (`on`, `off`, `flip`, `blink`, `loop`) chạy non-blocking với hàm `millis()`.

Minh họa khả năng cấu hình đa nền tảng phần cứng trên PlatformIO bằng `platformio.ini`:
- Chip ESP32 (lõi kép Xtensa)
- Chip ESP32-C3 (lõi đơn RISC-V)
- Chip ESP32-S3 N16R8 (lõi kép Xtensa, cấu hình Flash QIO và 8MB PSRAM OPI)

## Lưu ý kỹ thuật khi chạy thực tế

- **Lựa chọn môi trường build:** Đặt `default_envs = esp32-s3-n16r8` trong `platformio.ini` để tránh việc PlatformIO tự động nạp nhầm bản chip khác dẫn đến báo lỗi lệch chip (`A fatal error occurred: This chip is ESP32-S3, not ESP32`).
- **Thao tác nút BOOT (GPIO 0):** Vì GPIO 0 là chân quyết định chế độ bootloader của ESP32, khi bấm double click hoặc single click cần thao tác dứt khoát, không giữ phím quá lâu để tránh việc mạch vô tình bị treo vào chế độ nạp flash.
