#pragma once

#include <HAL/RunnableThread.h>
#include <functional>
#include <HAL/Runnable.h>

class LambdaFunctionRunnable : public FRunnable
{
public:
	static FRunnableThread* RunThreaded(FString threadName, std::function<void()> f);
	virtual void Exit() override;
	virtual uint32 Run() override;

protected:
	LambdaFunctionRunnable(std::function<void()> f);
	std::function<void()> _f;
	FRunnableThread* thread;
};
