#include "QuitOption.h"
#include "EventManager.h"
#include "SDBMHash.h"

namespace
{
	constexpr char8_t* const QuitEventString = "QuitEvent";
	constexpr int32_t QuitEventStringLength =
#ifndef constexpr
		constexpr_strlen(QuitEventString);
#else
		9;
#endif
	constexpr int32_t QuitEvent = SDBMCalculator<QuitEventStringLength>::CalculateValue(QuitEventString);
}

void QuitOption::Evaluate(Player& player)
{
	Notify<&QuitObserver::OnQuit>();
}