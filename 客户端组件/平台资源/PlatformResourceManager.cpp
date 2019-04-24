#include "StdAfx.h"
#include "Platformresourcemanager.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
//���캯��
CPlatformResourceManager::CPlatformResourceManager(void)
{
}

//��������
CPlatformResourceManager::~CPlatformResourceManager(void)
{
}

//�ӿڲ�ѯ
VOID * CPlatformResourceManager::QueryInterface(REFGUID Guid, DWORD dwQueryVer)
{
	QUERYINTERFACE(IPlatformResource,Guid,dwQueryVer);
	QUERYINTERFACE_IUNKNOWNEX(IPlatformResource,Guid,dwQueryVer);
	return NULL;
}

//������Դ
bool CPlatformResourceManager::LoadDefaultResource(LPCTSTR pszXmlName,HINSTANCE hInstance)
{
	//������Դ·��	
	CPaintManagerUI::SetInstance(hInstance);  
	CPaintManagerUI::SetResourceDll(GetModuleHandle(PLATFORM_RESOURCE_DLL_NAME));
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()+TEXT("Resource"));

	//��������
	CResourceLoader RecourceLoader;
	return RecourceLoader.LoadResource(pszXmlName,NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//�����������
DECLARE_CREATE_MODULE(PlatformResourceManager);

/////////////////////////////////////////////////////////////////////////////////////////////////
