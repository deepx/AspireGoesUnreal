#include "AspireGoesUnrealBPLibrary.h"
#include "AspireGoesUnreal.h"

DEFINE_LOG_CATEGORY(LogAspireGoesUnreal);

UAspireGoesUnrealBPLibrary::UAspireGoesUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	UE_LOG(LogAspireGoesUnreal, Warning, TEXT("AspireGoesUnreal loaded."));

}

TMap<FString, FString> UAspireGoesUnrealBPLibrary::GetAspireServices(bool useHttps)
{
	TMap<FString, FString> environmentVariables;
	environmentVariables.Empty();
	for (char ** current = environ; *current; current++)
	{
		FString envVar(*current);
		FString key;
		key.Empty();
		FString temp;
		temp.Empty();
		int32 position = envVar.Find("=");

		key = envVar.Left(position);
		
		if (key.Contains("services__"))
		{
			temp = key.Right(key.Len() - 10);
			if (useHttps && temp.Contains("__https__"))
			{
				key.Empty();
				key = temp.Replace(TEXT("__https_"), TEXT(""), ESearchCase::IgnoreCase);
				FString value = envVar.Right(envVar.Len() - position - 1);
				environmentVariables.Add(key, value);
			}
			else if(!useHttps && temp.Contains("__http__"))
			{
				key.Empty();
				key = temp.Replace(TEXT("__http_"), TEXT(""), ESearchCase::IgnoreCase);
				FString value = envVar.Right(envVar.Len() - position - 1);
				environmentVariables.Add(key, value);
			}
		}
	}
	return environmentVariables;
}

TMap<FString, FString> UAspireGoesUnrealBPLibrary::GetAspireConnectionStrings()
{
	TMap<FString, FString> connectionStrings;
	connectionStrings.Empty();

	for (char** current = environ; *current; current++)
	{
		FString envVar(*current);
		FString key;
		FString temp;
		key.Empty();
		temp.Empty();
		int32 position = envVar.Find("=");
		temp = envVar.Left(position);
		if (temp.Contains("ConnectionStrings__"))
		{
			key = temp.Replace(TEXT("ConnectionStrings__"), TEXT(""), ESearchCase::IgnoreCase);
			FString value = envVar.Right(envVar.Len() - position - 1);
			connectionStrings.Add(key, value);
		}
	}

	return connectionStrings;
}

