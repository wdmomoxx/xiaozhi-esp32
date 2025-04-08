#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "board.h"
#include "boards/common/wifi_board.h"
#include "boards/esp32-cgc-144/config.h"
#include "iot/thing.h"

#include "audio_codec.h"

#define TAG "BoardControl"

namespace iot {

class BoardControl : public Thing {
public:
    BoardControl() : Thing("BoardControl", "当前 AI 机器人管理和控制") {
	
        // // 修改重新配网
        // methods_.AddMethod("ResetWifiConfiguration", "重新配网", ParameterList(), 
        //     [this](const ParameterList& parameters) {
        //         ESP_LOGI(TAG, "ResetWifiConfiguration");
        //         auto board = static_cast<WifiBoard*>(&Board::GetInstance());
        //         if (board && board->GetBoardType() == "wifi") {
        //             board->ResetWifiConfiguration();
        //         }
        //     });

        // 修改音量调节
        properties_.AddNumberProperty("volume", "当前音量值", [this]() -> int {
            auto codec = Board::GetInstance().GetAudioCodec();
            return codec->output_volume();
        });

        // 定义设备可以被远程执行的指令
        methods_.AddMethod("SetVolume", "设置音量", ParameterList({
            Parameter("volume", "0到100之间的整数", kValueTypeNumber, true)
        }), [this](const ParameterList& parameters) {
            auto codec = Board::GetInstance().GetAudioCodec();
            // 获取传入的音量值
            int volume = parameters["volume"].number();
            // 限制音量值不超过66
            if (volume > 66) {
                volume = 66;
            }
            codec->SetOutputVolume(static_cast<uint8_t>(volume));
        });
    }
};

} // namespace iot

DECLARE_THING(BoardControl); 
