#include "moho.h"

class CwaitHandleSet: public Moho
{
	public:
	CwaitHandleSet();
	
	void AddHandle(void *a2);
	void RemoveHandle(void *a2); 
	void MsgWaitEx(DWORD dwMilliseconds, DWORD dwWakeMask, unsigned int dwFlags); 
		
	private:

	int handle;
		
};
