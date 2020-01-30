#pragma once

#include "IEntity.h"

namespace Freeking::Entity::Cast
{
    class ABumSit : public BaseEntity
    {
    public:

        ABumSit();

		virtual void Initialize() override;
		virtual void Tick(double dt) override;

	protected:

		virtual bool SetProperty(const EntityKeyValue& keyValue) override;

    private:

    };
}