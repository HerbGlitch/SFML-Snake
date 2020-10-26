#pragma once

namespace herbglitch {
    class State {
    public:
        virtual void update() = 0;
        virtual void render() = 0;
    };
}