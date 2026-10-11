#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    void keyDown(cocos2d::enumKeyCodes key) {
        PlayLayer::keyDown(key);

        // По нажатию на английскую кнопку K (или русскую Л)
        if (key == cocos2d::enumKeyCodes::KEY_K) {
            if (this->m_level->isPlatformer()) {
                
                // Принудительно выставляем нужную комнату
                this->m_currentRoom = 742;
                
                // Создаем чекпоинт, чтобы игра зафиксировала нас
                this->storeCheckpoint(this->m_player1->getPosition());
                
                // Перезагружаем экран, чтобы появиться в 742 комнате
                this->resetLevel();

                Notification::create("Телепорт в 742 успешен!", NotificationIcon::Success)->show();
            }
        }
    }
};
