#include <GUIViewer/demo.h>

void about_dialog(int &x, int &y) {
	static bool is_floating = false;
	AyaGui::BeginDialog(is_floating ? LayoutStrategy::Floating : LayoutStrategy::Fixed, x, y, "About AyaGui", 500, 430);
	AyaGui::MultilineText("AyaGui is a lite imgui graphical user interface library in Modern C++ and OpenGL developed by g1n0st, inspired by Dear imgui. \
		It is lite, portable and self - contained(no external dependencies) \
		You can easily integrate it into your 3D - pipeline enabled application at any time. \n\n\
		AyaGui is designed to enable fast iterations and to empower programmers to create content creation tools  \
		and visualization / debug tools(as opposed to UI for the average end - user). \
		It favors simplicity and productivity toward this goal, \
		and lacks certain features normally found in more high - level libraries. \n\n\
		AyaGui is particularly suited to integration in games engine(for tooling), real - time 3D applications,  \
		fullscreen applications, embedded applications, or any applications on consoles platforms where operating system features are non - standard. \n\n");
	
	AyaGui::Line();
	AyaGui::Text("If you find any issue in AyaGui or require more widgets, ");
	AyaGui::Text("please post issue on Github, or contact g1n0st: ");
	AyaGui::Text(Color4f(0.95f, 0.95f, 0.95f, 0.95f), "g1n0st@live.com");
	AyaGui::ExpandVertical();
	AyaGui::CheckBox("Set it floating", is_floating);
	AyaGui::EndDialog();
}
void test_dialog(int &x, int &y, bool banned) {
	if (!banned) {
		AyaGui::BeginDialog(LayoutStrategy::Floating, x, y, "Test Dialog (normal)", 400, 500);
	}
	else {
		AyaGui::BeginDialog(LayoutStrategy::Floating, x, y, "Test Dialog (banned)", 400, 500);
	}

	static int content_height;
	static float scroller;
	AyaGui::BeginScroller(400, content_height, scroller);

	AyaGui::Text("Text test");
	AyaGui::MultilineText("MultilineText text in line1 \n MultilineText text in line2");

	static int hello_num = 0;
	if (AyaGui::Button("Hello Button", 200, 24, banned)) hello_num++;
	AyaGui::Text("Hello time: %d", hello_num);

	static float r = 1.0f, g = 1.0f, b = 1.0f;
	AyaGui::Horizontal();
	AyaGui::Slider<float>("R", r, 0.0f, 1.f, 50, banned);
	AyaGui::Slider<float>("G", g, 0.0f, 1.f, 50, banned);
	AyaGui::Slider<float>("B", b, 0.0f, 1.f, 50, banned);
	AyaGui::ColorBlock(r, g, b);
	AyaGui::NextLine(60);
	AyaGui::Vertical();
	AyaGui::Text(Color4f(r, g, b, 1.0f), "Colorful Text, r=%.2f, g=%.2f, b=%.2f", r, g, b);

	AyaGui::NextLine(20);
	AyaGui::Horizontal();
	static float float_val = 0.0f;
	AyaGui::Slider<float>("Float slider: ", float_val, 0.0f, 100.f, 200, banned);

	AyaGui::NextLine(25);
	AyaGui::Horizontal();
	static int int_val = 0;
	AyaGui::Slider<int>("Int slider:    ", int_val, 0, 100, 200, banned);

	AyaGui::NextLine(25);
	AyaGui::Horizontal();
	static char char_val = 0;
	AyaGui::Slider<char>("Char slider:  ", char_val, 'A', 'Z', 200, banned);

	AyaGui::NextLine(25);
	AyaGui::Vertical();
	static int selected = -1;
	AyaGui::ComboBox("Combo box",
		{ "Vertex CM",
		"Multiplex MLT",
		"Bidirectional PT",
		"Path Tracing",
		"Direct Lighting" },
		selected, 140, banned);

	if (selected >= 0) {
		AyaGui::Text("You selected item id: %d", selected);
	}
	else {
		AyaGui::Text("You have not selected any item yet.");
	}

	AyaGui::NextLine(20);
	static int ratio_val;
	AyaGui::RadioButton(ratio_val == 1 ? "Option #1 (selected)" : "Option #1", 1, ratio_val, banned);
	AyaGui::RadioButton(ratio_val == 2 ? "Option #2 (selected)" : "Option #2", 2, ratio_val, banned);
	AyaGui::RadioButton(ratio_val == 3 ? "Option #2 (selected)" : "Option #2", 3, ratio_val, banned);

	AyaGui::NextLine(20);
	static bool checked_1 = false;
	AyaGui::CheckBox(!checked_1 ? "Check me!" : "Checked 1st Checkbox!", checked_1, banned);
	static bool checked_2 = false;
	AyaGui::CheckBox(!checked_2 ? "Check me!" : "Checked 2nd Checkbox!", checked_2, banned);
	static bool checked_3 = false;
	AyaGui::CheckBox(!checked_3 ? "Check me!" : "Checked 3rd Checkbox!", checked_3, banned);

	AyaGui::Text("Input Text: ");
	static std::string str1;
	AyaGui::InputText(str1, 200, false, false, banned);
	static int digit;
	AyaGui::InputDigit("Input Digit: ", digit, banned);
	AyaGui::EndScroller(400, content_height, scroller);

	AyaGui::EndDialog();
}
void demo_dialog() {
	static int about_x = 50, about_y = 50;
	static int test_x = 600, test_y = 50;
	static bool showed = false;
	static bool banned = false;

	AyaGui::BeginFrame();

	AyaGui::BeginSidebarDialog(LayoutStrategy::DockRight);
	if (AyaGui::CollapsingHeader("Dialog Control Pannel", showed)) {
		AyaGui::InputDigit("About Dialog Xpos: ", about_x);
		AyaGui::InputDigit("About Dialog Ypos: ", about_y);
		AyaGui::InputDigit("Test Dialog Xpos: ", test_x);
		AyaGui::InputDigit("Test Dialog Ypos: ", test_y);

		AyaGui::CheckBox("Ban widgets: ", banned);
	}
	AyaGui::EndDialog();

	about_dialog(about_x, about_y);
	test_dialog(test_x, test_y, banned);

	AyaGui::EndFrame();
}