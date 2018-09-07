#include <vita2d.h>
#include <vitasdk.h>


int main() {

	int run = 1;

	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));


	while (run) {
		vita2d_start_drawing();
		vita2d_clear_screen();


		vita2d_end_drawing();
		vita2d_swap_buffers();
	}
	vita2d_fini();

	sceKernelExitProcess(0);
	return (0);
}
